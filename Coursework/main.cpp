// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <vector>

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
  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = int(fa[i].real() + 0.5);

  // нормализация
  for (int i = 0; i < n - 1; i++) {
    result[i + 1] += result[i] / 10;
    result[i] %= 10;
  }
  while (result.size() > 1 && result.back() == 0) result.pop_back();
  return result;
}

int main() {
  vector<int> a, b;
  string s;

  ifstream fin("numbers/1.txt");
  fin >> s;
  fin.close();
  cout << "Number 1 size: " << s.size() << endl;
  for (int i = s.size() - 1; i >= 0; i--) a.push_back(s[i] - '0');

  fin.open("numbers/2.txt");
  fin >> s;
  fin.close();
  cout << "Number 2 size: " << s.size() << endl;
  for (int i = s.size() - 1; i >= 0; i--) b.push_back(s[i] - '0');

  vector<int> c = multiply(a, b);
  ofstream fout("numbers/output.txt");
  cout << "Result size: " << c.size() << endl;
  for (int i = c.size() - 1; i >= 0; i--) fout << c[i];
  return 0;
}