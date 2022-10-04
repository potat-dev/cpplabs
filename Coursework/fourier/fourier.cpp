// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#include "fourier.h"

#include <cmath>
#include <complex>
#include <vector>

using namespace std;

constexpr double M_2PI = 2 * M_PI;

void fft(vector<base> &a, bool invert) {
  size_t n = a.size();
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