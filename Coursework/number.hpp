#pragma once

#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <vector>

class Number {
 private:
  std::vector<int> digits;
  bool negative = false;

 public:
  Number() : Number(0) {}  // default constructor

  Number(const std::string &s) {
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '-') {
        negative = true;
        break;
      }
      if (s[i] >= '0' && s[i] <= '9') {
        digits.push_back(s[i] - '0');
      } else {
        throw std::invalid_argument("Invalid number");
      }
    }
  }

  Number(const int64_t &n) {
    if (n < 0) {
      negative = true;
    }
    int64_t m = abs(n);
    while (m > 0) {
      digits.push_back(m % 10);
      m /= 10;
    }
  }

  Number(const std::vector<int> &v, bool n = false) : digits(v), negative(n) {}

  const size_t size() const { return digits.size(); }
  const bool is_negative() const { return negative; }
  const std::vector<int> &get_digits() const { return digits; }
  const int operator[](const size_t &i) const { return digits[i]; }

  void set(const std::string &s) {
    digits.clear();
    negative = false;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '-') {
        negative = true;
        break;
      }
      if (s[i] >= '0' && s[i] <= '9') {
        digits.push_back(s[i] - '0');
      } else {
        throw std::invalid_argument("Invalid number");
      }
    }
  }

  friend std::ostream &operator<<(std::ostream &out, const Number &n) {
    if (n.negative) out << '-';
    for (int i = n.digits.size() - 1; i >= 0; i--) {
      out << n.digits[i];
    }
    return out;
  }
};