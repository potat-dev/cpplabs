#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

// 18 446 744 073 709 600 000

using namespace std;

constexpr double M_2PI = 2 * 3.14159265358979323846;
typedef std::complex<double> base;

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

vector<int> str_to_bignum(string s, size_t parts) {
  vector<int> a;
  for (int i = s.size() - 1; i >= 0; i -= parts) {
    int num = 0;
    for (int j = 0; j < parts; j++) {
      if (i - j >= 0) {
        num += (s[i - j] - '0') * pow(10, j);
      }
    }
    a.push_back(num);
  }
  return a;
}

string fill_zeros(string s, size_t parts) {
  while (s.size() % parts != 0) {
    s = '0' + s;
  }
  return s;
}

string bignum_to_str(vector<int64_t> a, size_t parts) {
  string s;
  for (int i : a) s = fill_zeros(to_string(i), parts) + s;
  // remove leading zeros
  while (s[0] == '0') s.erase(0, 1);
  return s;
}

int main() {
  string s1, s2;
  s1 = "123456789675483987398739999999999999999999999999999999999";
  s2 = "98765432167548398739873";
  int BASE_POW = 7;
  int BASE = pow(10, BASE_POW);
  vector<int> a = str_to_bignum(s1, BASE_POW);
  vector<int> b = str_to_bignum(s2, BASE_POW);

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < b.size(); i++) {
    cout << b[i] << " ";
  }
  cout << endl;

  vector<base> fa(a.begin(), a.end());
  vector<base> fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n), fb.resize(n);

  fft(fa, false), fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<int64_t> result(n, 0);
  for (int i = 0; i < n; i++) {
    result[i] = int64_t(fa[i].real() + 0.5);
  }

  for (int i = 0; i < n; i++) {
    cout << fa[i].real() << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  // normalize
  for (int i = 0; i < n; i++) {
    if (result[i] >= BASE) {
      result[i + 1] += result[i] / BASE;
      result[i] %= BASE;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  while (result.size() > 1 && result.back() == 0) result.pop_back();

  string s = bignum_to_str(result, BASE_POW);
  cout << s << endl;

  cout << "12193263186317303248211739666560438427187960019999999999901234567832451601260127" << endl;
  if (s == "12193263186317303248211739666560438427187960019999999999901234567832451601260127") {
    cout << "OK" << endl;
  } else {
    cout << "FAIL" << endl;
  }
  return 0;
}