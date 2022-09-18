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

class Number {
 private:
  vector<int> digits;
  bool negative = false;

 public:
  Number() {} // default constructor
  
  Number(const string &s) {
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '-') {
        negative = true;
        break;
      }
      if (s[i] >= '0' && s[i] <= '9') {
        digits.push_back(s[i] - '0');
      } else {
        throw invalid_argument("Invalid number");
      }
    }
  }

  Number(const vector<int> &v, bool n = false) : digits(v), negative(n) {}
  const size_t size() const { return digits.size(); }

  friend ostream &operator<<(ostream &out, const Number &n) {
    if (n.negative) out << '-';
    for (int i = n.digits.size() - 1; i >= 0; i--) {
      out << n.digits[i];
    }
    return out;
  }

  Number fft_multiply(const Number &other) const {
    // TODO: optimize on really big numbers (> 1M digits)
    vector<int> result = ::multiply(digits, other.digits);
    return Number(result, negative ^ other.negative);
  }

  Number simple_multiply(const Number &other) const {
    vector<int> result(size() + other.size(), 0);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < other.size(); j++) {
        result[i + j] += digits[i] * other.digits[j];
      }
    }
    for (int i = 0; i < result.size() - 1; i++) {
      result[i + 1] += result[i] / 10;
      result[i] %= 10;
    }
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return Number(result, negative ^ other.negative);
  }
};
