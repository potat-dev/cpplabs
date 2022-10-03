// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#include "fourier.h"

#include <cmath>
#include <complex>
#include <vector>

using namespace std;

constexpr double M_2PI = 2 * M_PI;

void fft(vector<base> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = M_2PI / len * (invert ? -1 : 1);
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

vector<uint16_t> multiply(vector<uint16_t> const &a,
                          vector<uint16_t> const &b) {
  vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n), fft(fa, false);
  fb.resize(n), fft(fb, false);

  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<uint16_t> result(n);
  for (int i = 0; i < n; i++) result[i] = uint16_t(fa[i].real() + 0.5);

  for (int i = 0; i < n - 1; i++) {
    result[i + 1] += result[i] / 10;
    result[i] %= 10;
  }

  while (result.size() > 1 && result.back() == 0) result.pop_back();
  return result;
}
