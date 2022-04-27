#include "HugeInt.h"

using namespace std;

// конструкторы

HugeInt::HugeInt(string str, int digits) {
  minus = (str[0] == '-');
  if (minus) str.erase(0, 1);
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
  if (digit_count > capacity) {
    capacity = digit_count;
    array.resize(capacity);
  }
  for (int i = 0; i < digit_count; i++) {
    array[i] = str[digit_count - i - 1] - '0';
  }
}

string HugeInt::to_str() {
  string temp;
  if (minus) temp = "-";
  for (int i = digit_count - 1; i > -1; i--)
    temp += (char) array[i] + '0';
  return temp;
}

void HugeInt::remove_leading_zeros() {
  while (this->digit_count > 1 && this->array.back() == 0) {
    this->array.pop_back();
    this->digit_count -= 1;
  }
  if (this->digit_count == 1 && this->array[0] == 0) this->minus = false;
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

ifstream& operator>>(ifstream &in, HugeInt &a) {
  string str;
  in >> str;
  a.set(str);
  return in;
}

ostream& operator<<(ostream &out, const HugeInt &a) {
  if (a.minus) out << "-";
  for (int i = a.digit_count - 1; i > -1; i--)
    out << (char) (a.array[i] + '0');
  return out;
}

ofstream& operator<<(ofstream &out, HugeInt &a) {
  out << a.to_str();
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

bool operator==(const HugeInt &a, long long value) {
  return a == (HugeInt) value;
}

bool operator==(long long value, const HugeInt &a) {
  return a == (HugeInt) value;
}

bool operator!=(const HugeInt &a, const HugeInt &b) {
  return !(a == b);
}

bool operator!=(const HugeInt &a, long long value) {
  return !(a == (HugeInt) value);
}

bool operator!=(long long value, const HugeInt &a) {
  return !(a == (HugeInt) value);
}

// operator <

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

bool operator<(const HugeInt &a, long long b) {
  return a < (HugeInt) b;
}

bool operator<(long long a, const HugeInt &b) {
  return (HugeInt) a < b;
}

// operator <=

bool operator<=(const HugeInt &a, const HugeInt &b) {
  return (a < b || a == b);
}

bool operator<=(const HugeInt &a, long long b) {
  HugeInt temp(b);
  return (a < temp || a == temp);
}

bool operator<=(long long a, const HugeInt &b) {
  HugeInt temp(a);
  return (temp < b || temp == b);
}

// operator >

bool operator>(const HugeInt&a, const HugeInt &b) {
  return b < a;
}

bool operator>(const HugeInt &a, long long b) {
  return (HugeInt) b < a;
}

bool operator>(long long a, const HugeInt &b) {
  return b < (HugeInt) a;
}

// operator >=

bool operator>=(const HugeInt &a, const HugeInt &b) {
  return (b < a || a == b);
}

bool operator>=(const HugeInt &a, long long b) {
  HugeInt temp(b);
  return (temp < a || a == temp);
}

bool operator>=(long long a, const HugeInt &b) {
  HugeInt temp(a);
  return (b < temp || temp == b);
}

// проверки на ноль и минус

bool HugeInt::is_zero() {
  return (*this == (HugeInt) 0);
}

bool HugeInt::has_minus() {
  return minus;
}

// смена знака

HugeInt HugeInt::operator-() const {
  return HugeInt(*this, true);
}

HugeInt habs(const HugeInt &value) {
  return value < 0 ? -value : value;
}

// операторы + -
// TODO: исправить работу +/-

HugeInt operator+(HugeInt a, const HugeInt &b) {
  // описано лишь сложение двух положительных чисел
  // остальное - используя смену знака и вычитание

  HugeInt right(b);
  if (a.has_minus()) {
    if (right.has_minus()) return -(-a + (-right));
    else return right - (-a);
  } else if (right.has_minus()) return a - (-right);

  int carry = 0; // флаг переноса
  for (int i = 0; i < max(a.digit_count, right.digit_count) || carry != 0; ++i) {
    if (i == a.digit_count) a.array.push_back(0);
    a.array[i] += carry + (i < right.digit_count ? right.array[i] : 0);
    carry = a.array[i] >= 10;
    if (carry != 0) a.array[i] -= 10;
  }

  return a;
}

HugeInt operator+(const HugeInt &a, long long value) {
  return a + (HugeInt) value;
}

HugeInt operator+(long long value, const HugeInt &a) {
  return (HugeInt) value + a;
}

HugeInt operator-(HugeInt a, const HugeInt &b) {
  HugeInt right(b);
  if (right.has_minus()) return a + (-right);
  else if (a.has_minus()) return -(-a + right);
  else if (a < right) return -(right - a);

  int carry = 0;
  for (int i = 0; i < right.digit_count || carry != 0; ++i) {
    a.array[i] -= carry + (i < right.digit_count ? right.array[i] : 0);
    carry = a.array[i] < 0;
    if (carry != 0) a.array[i] += 10;
  }

  a.remove_leading_zeros();
  return a;
}

HugeInt operator-(const HugeInt &a, long long value) {
  return a - (HugeInt) value;
}

HugeInt operator-(long long value, const HugeInt &a) {
  return (HugeInt) value - a;
}