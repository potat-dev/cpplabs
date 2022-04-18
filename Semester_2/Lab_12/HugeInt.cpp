#include <iostream>
#include <string>
#include <vector>

#include "HugeInt.h"

using namespace std;

// конструкторы

HugeInt::HugeInt(string str, int digits) {
  minus = (str[0] == '-');
  if (minus) str.erase(0, 1);
  // cout << "str: " << str << endl;
  digit_count = str.length();
  capacity = digit_count > digits ? digit_count : digits;
  array.resize(capacity);
  for (int i = 0; i < digit_count; i++)
    array[i] = str[digit_count - i - 1] - '0';
}

HugeInt::HugeInt(long long n):
  HugeInt(to_string(n)) {
}

HugeInt::HugeInt(const HugeInt &temp, bool invert):
  array(temp.array), 
  digit_count(temp.digit_count),
  capacity(temp.capacity),
  minus(temp.minus ^ invert) {
}

// сеттеры и геттеры

void HugeInt::set(string str) {
  minus = (str[0] == '-');
  if (minus) str.erase(0, 1);
  digit_count = str.length();
  for (int i = 0; i < digit_count; i++)
    array[i] = str[digit_count - i - 1] - '0';
}

string HugeInt::to_str() {
  string temp;
  if (minus) temp = "-";
  for (int i = digit_count - 1; i > -1; i--)
    temp += (char) array[i] + '0';
  return temp;
}

// операторы присваивания

HugeInt& HugeInt::operator=(const HugeInt &temp) {
  array = temp.array;
  digit_count = temp.digit_count;
  capacity = temp.capacity;
  minus = temp.minus;
  return *this;
}

HugeInt& HugeInt::operator=(const long long &temp) {
  *this = (HugeInt) temp;
  return *this;
}

HugeInt& HugeInt::operator=(const string &str) {
  this->set(str);
  return *this;
}

// ввод / вывод

istream& operator>>(istream &in, HugeInt &a) {
  string str;
  in >> str;
  a.set(str);
  return in;
}

ostream& operator<<(ostream &out, const HugeInt &a) {
  if (a.minus) cout << "-";
  for (int i = a.digit_count - 1; i > -1; i--)
    cout << (char) (a.array[i] + '0');
  return out;
}

// операторы сравнения

bool operator==(const HugeInt &a, const HugeInt &b) {
  if (a.digit_count == b.digit_count && a.minus == b.minus) {
    for (int i = 0; i < a.digit_count; i++)
      if (a.array[i] != b.array[i]) return false;
    return true;
  } else return false;
}

bool operator!=(const HugeInt &a, const HugeInt &b) {
  return !(a == b);
}

bool operator<(const HugeInt &a, const HugeInt &b) {
  if (a.minus == b.minus) {
    if (a.minus) {
      // если оба отрицательные
      if (a.digit_count == b.digit_count) {
        // сравниваем каждую цифру
        for (int i = 0; i < a.digit_count; i++)
          if (a.array[i] == b.array[i]) continue;
          else return (a.array[i] > b.array[i]);
        return false;
      } else return (a.digit_count > b.digit_count);
    } else {
      // если оба положительные
      if (a.digit_count == b.digit_count) {
        for (int i = 0; i < a.digit_count; i++)
          if (a.array[i] == b.array[i]) continue;
          else return (a.array[i] < b.array[i]);
        return false;
        // сравниваем каждую цифру
      } else return (a.digit_count < b.digit_count);
    }
  } else return a.minus;
}

bool operator<=(const HugeInt &a, const HugeInt &b) {
  return (a < b || a == b);
}

bool operator>(const HugeInt&a, const HugeInt &b) {
  return b < a;
}

bool operator>=(const HugeInt &a, const HugeInt &b) {
  return (b < a || a == b);
}

// проверки на ноль и минус

bool HugeInt::is_zero() {
  return (*this == (HugeInt) 0);
}

bool HugeInt::has_minus() {
  return minus;
}

// смена знака

const HugeInt HugeInt::operator-() {
  return HugeInt(*this, true);
}