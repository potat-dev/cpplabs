#include "number.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../fourier/fourier.h"

using namespace std;

Number::Number() : digits(1, 0), negative(false) {}

Number::Number(const string &s) { set(s); }

Number::Number(const int64_t &n) {
  if (n < 0) negative = true;
  int64_t m = n < 0 ? -n : n;
  while (m > 0) {
    digits.push_back(m % 10);
    m /= 10;
  }
}

Number::Number(const vector<int> &v, bool n) : digits(v), negative(n) {}

size_t Number::size() const { return digits.size(); }
bool Number::is_negative() const { return negative; }
uint16_t Number::operator[](const size_t &i) const { return digits[i]; }

void Number::set(const string &s) {
  digits.clear();
  if (s.empty()) throw invalid_argument("Invalid number");
  negative = s.at(0) == '-';

  for (int i = s.size() - 1; i >= negative; i--) {
    if (s[i] >= '0' && s[i] <= '9') {
      digits.push_back(s[i] - '0');
    } else {
      throw invalid_argument("Invalid number");
    }
  }

  if (digits.empty()) throw invalid_argument("Invalid number");
  while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
  if (digits.size() == 1 && digits[0] == 0) negative = false;
}

void Number::load(const string &filename) {
  ifstream in(filename);
  if (!in.is_open()) throw invalid_argument("File not found");
  string s;
  in >> s;
  set(s);
}

void Number::save(const string &filename) {
  ofstream out(filename);
  if (!out.is_open()) throw invalid_argument("File not found");
  out << *this;
}

ostream &operator<<(ostream &out, const Number &n) {
  if (n.negative) out << '-';
  for (int i = n.digits.size() - 1; i >= 0; i--) out << (int)n.digits[i];
  return out;
}

// multiplication algorithms

Number fft_multiply(const Number &a, const Number &b) {
  vector<base> fa(a.digits.begin(), a.digits.end());
  vector<base> fb(b.digits.begin(), b.digits.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n), fb.resize(n);

  fft(fa, false), fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = int(fa[i].real() + 0.5);
  }

  for (int i = 0; i < n - 1; i++) {
    result[i + 1] += result[i] / 10;
    result[i] %= 10;
  }

  while (result.size() > 1 && result.back() == 0) result.pop_back();
  return Number(result, a.negative != b.negative);
}

Number column_multiply(const Number &a, const Number &b) {
  vector<int> result(a.size() + b.size(), 0);
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