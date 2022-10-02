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
    digits.push_back(m % BASE);
    m /= BASE;
  }
}

Number::Number(const vector<long> &v, bool n) : digits(v), negative(n) {}

size_t Number::size() const { return digits.size(); }
bool Number::is_negative() const { return negative; }
int Number::operator[](const size_t &i) const { return digits[i]; }

void Number::set(const string &s) {
  digits.clear();
  if (s.empty()) throw invalid_argument("Invalid number");
  negative = s.at(0) == '-';

  size_t base_len = to_string(BASE - 1).size();
  string temp(base_len, ' ');
  for (int i = s.size() - 1; i >= negative; i--) {
    int j = (s.size() - i - 1) % base_len;
    if (s[i] >= '0' && s[i] <= '9') {
      temp[base_len - j - 1] = s[i];
      if (j == base_len - 1) {
        digits.push_back(stol(temp));
        temp = string(base_len, ' ');
      }
    } else {
      throw invalid_argument("Invalid number");
    }
  }
  if (!temp.empty()) digits.push_back(stol(temp));

  // remove leading zeros
  while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
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
  for (int i = n.digits.size() - 1; i >= 0; i--) out << n.digits[i];
  return out;
}

// multiplication algorithms

Number fft_multiply(const Number &a, const Number &b) {
  return Number(multiply(a.digits, b.digits),
                a.is_negative() ^ b.is_negative());
}

Number column_multiply(const Number &a, const Number &b) {
  vector<long> result(a.size() + b.size(), 0);
  long long temp = 0;

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      temp = result[i + j] + a[i] * b[j];
      result[i + j] = temp % BASE;
      if (i + j + 1 < result.size()) {
        result[i + j + 1] += temp / BASE;
      }
    }
  }

  while (result.size() > 1 && result.back() == 0) result.pop_back();
  return Number(result, a.is_negative() ^ b.is_negative());
}