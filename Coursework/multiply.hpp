// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#pragma once

#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <vector>

#include "number.hpp"

using namespace std;
typedef complex<double> base;

void fft(vector<base> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * M_PI / len * (invert ? -1 : 1);
    base wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      base w(1);
      for (int j = 0; j < len / 2; j++) {
        base u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (base &x : a) x /= n;
}

vector<int> multiply(vector<int> const &a, vector<int> const &b) {
  vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n), fft(fa, false);
  fb.resize(n), fft(fb, false);

  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = int(fa[i].real() + 0.5);

  for (int i = 0; i < n - 1; i++) {
    result[i + 1] += result[i] / 10;
    result[i] %= 10;
  }

  while (result.size() > 1 && result.back() == 0) result.pop_back();
  return result;
}

Number fft_multiply(const Number &a, const Number &b) {
  vector<int> result = multiply(a.get_digits(), b.get_digits());
  return Number(result, a.is_negative() ^ b.is_negative());
}

Number column_multiply(const Number &a, const Number &b) {
  std::vector<int> result(a.size() + b.size(), 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      result[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i < result.size() - 1; i++) {
    result[i + 1] += result[i] / 10;
    result[i] %= 10;
  }
  while (result.size() > 1 && result.back() == 0) result.pop_back();
  return Number(result, a.is_negative() ^ b.is_negative());
}