// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
typedef complex<long double> base;

vector<base> fft(vector<base>& a) {
  int n = a.size();
  if (n == 1) return vector<base>(1, a[0]);
  vector<base> w(n);  /// complex roots
  for (int i = 0; i < n; i++) {
    double alpha = 2 * M_PI * i / n;
    w[i] = base(cos(alpha), sin(alpha));
  }

  vector<base> A0(n / 2), A1(n / 2);
  for (int i = 0; i < n / 2; i++) {
    A0[i] = a[i * 2];      /// Even coefficients
    A1[i] = a[i * 2 + 1];  /// Odd coefficients
  }

  vector<base> y0 = fft(A0);
  vector<base> y1 = fft(A1);
  vector<base> y(n);
  for (int k = 0; k < n / 2; k++) {
    y[k] = y0[k] + w[k] * y1[k];
    y[k + n / 2] = y0[k] - w[k] * y1[k];
  }
  return y;
}

vector<base> ifft(vector<base>& a)  /// Inverse FFT
{
  int n = a.size();
  if (n == 1) return vector<base>(1, a[0]);
  vector<base> w(n);
  for (int i = 0; i < n; i++) {
    double alpha = M_2_PI * i / n;
    w[i] = base(cos(alpha), sin(alpha));
  }
  vector<base> A0(n / 2), A1(n / 2);
  for (int i = 0; i < n / 2; i++) {
    A0[i] = a[i * 2];
    A1[i] = a[i * 2 + 1];
  }
  vector<base> y0 = ifft(A0);
  vector<base> y1 = ifft(A1);
  vector<base> y(n);
  for (int k = 0; k < n / 2; k++) {
    y[k] = y0[k] + y1[k] / w[k];  /// w[k]^-1
    y[k + n / 2] = y0[k] - y1[k] / w[k];
  }
  return y;
}

vector<long long> multiply(vector<long long>& a, vector<long long>& b) {
  vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  fa.resize(n);
  fb.resize(n);
  vector<base> fc = fft(fa);
  vector<base> fd = fft(fb);
  for (int i = 0; i < n; i++) fc[i] *= fd[i];
  vector<base> fr = ifft(fc);
  vector<long long> result(n);
  for (int i = 0; i < n; i++) result[i] = (long long)(fr[i].real() + 0.5);
  return result;
}

int main() {
  vector<long long> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<long long> b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<long long> c = multiply(a, b);
  for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
  return 0;
}