#include "HugeInt.h"
using namespace std;

// статьи в помощь, если захочешь разобраться:
// https://habr.com/ru/post/172285/ (перегрузка оперторов)
// https://habr.com/ru/post/124258/ (умножение)
// https://www.cyberforum.ru/cpp-beginners/thread1955526.html (остаток от деления)

HugeInt::HugeInt() {
  for (int i = 0; i < 40; i++) {
    number[i] = 0;
  }
  depth = 0;
  negative = false;
}

HugeInt::HugeInt(string str) : HugeInt(str.size()) {
  set(str);
  shrink_to_fit();
}

HugeInt::HugeInt(int d) {
  for (int i = 0; i < 40; i++) {
    number[i] = 0;
  }
  depth = d;
  negative = false;
}

HugeInt::HugeInt(int num[40], int dep) {
  for (int i = 0; i < 40; i++) {
    number[i] = num[i];
  }
  depth = dep;
  negative = false;
}

void HugeInt::set(string str) {
  if (str[0] == '-') {
    depth = str.length() - 1;
    negative = true;
    int j = 0;
    for (int i = str.length() - 1; i > 0; i--) {
      number[j++] = str[i] - 48;
    }
  } else {
    depth = str.length();
    negative = false;
    int j = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
      number[j++] = str[i] - 48;
    }
  }
  shrink_to_fit();
}

void HugeInt::set(int num[40]) {
  for (int i = 0; i < 40; i++) {
    number[i] = num[i];
  }
  shrink_to_fit();
}

string HugeInt::to_str() const {
  string str;
  if (negative) {
    str += '-';
    for (int i = depth - 1; i >= 0; i--) {
      str += number[i] + 48;
    }
  } else {
    for (int i = depth - 1; i >= 0; i--) {
      str += number[i] + 48;
    }
  }
  return str;
}

bool HugeInt::check_zero() const {
  for (int i = 0; i < depth; i++) {
    if (number[i]) return false;
  }
  return true;
}

// геттеры и сеттеры

void HugeInt::set_minus(bool state) {
  negative = state;
}

bool HugeInt::has_minus() const {
  return negative;
}

int HugeInt::get_depth() const {
  return depth;
}

void HugeInt::set_depth(int dep) {
  depth = dep;
}

void HugeInt::set_digit(int index, int digit) {
  number[index] = digit;
}

int HugeInt::get_digit(int index) const {
  return number[index];
}

int HugeInt::compare(HugeInt &b) const {
  if (negative && !b.negative) {
    return -1;
  } else if (!negative && b.negative) {
    return 1;
  } else if (!negative && !b.negative) {
    if (depth > b.depth) {
      return 1;
    } else if (b.depth < depth) {
      return -1;
    } else {
      for (int i = depth - 1; i >= 0; i--) {
        if (number[i] > b.number[i]) {
          return 1;
        } else if (number[i] < b.number[i]) {
          return -1;
        }
      }
      return 0;
    }
  } else if (negative && b.negative) {
    if (depth > b.depth) {
      return -1;
    } else if (b.depth < depth) {
      return 1;
    } else {
      for (int i = depth - 1; i >= 0; i--) {
        if (number[i] > b.number[i]) {
          return -1;
        } else if (number[i] < b.number[i]) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 0;
}

bool operator==(HugeInt &n1, HugeInt &n2) {
  return (n1.compare(n2) == 0);
}

bool operator!=(HugeInt &n1, HugeInt &n2) {
  return (n1.compare(n2) != 0);
}

bool operator>(HugeInt &n1, HugeInt &n2) {
  return (n1.compare(n2) == 1);
}

bool operator<=(HugeInt &n1, HugeInt &n2) {
  return (n1 < n2 || n1 == n2);
}

bool operator<(HugeInt &n1, HugeInt &n2) {
  return (n1.compare(n2) == -1);
}

bool operator>=(HugeInt &n1, HugeInt &n2) {
  return (n1 > n2 || n1 == n2);
}

HugeInt& HugeInt::operator++() {
  ++(*this);
  return *this;
}
 
HugeInt& HugeInt::operator--() {
  --(*this);
  return *this;
}
 
HugeInt HugeInt::operator++(int) {
  HugeInt temp(*this), c1("1");
  *this = *this + c1;
  return temp;
}
 
HugeInt HugeInt::operator--(int) {
  HugeInt temp(*this), c1("1");
  *this = *this - c1;
  return temp;
}

HugeInt HugeInt::simple_sum(HugeInt &b) {
  int max = 0;
  if (depth > b.depth) {
    max = depth;
  } else {
    max = b.depth;
  }
  int result[41] = {0};
  for (int i = 0; i < max; i++) {
    int tmp = (result[i] + number[i] + b.number[i]);
    result[i] = tmp % 10;
    result[i + 1] += tmp / 10;
  }
  if (result[max]) max++;
  HugeInt res(result, max);
  return res;
}

HugeInt HugeInt::simple_dif(HugeInt &b) {
  int result[41] = {0};
  for (int i = 0; i < depth; i++) {
    result[i] = number[i] - b.number[i];
  } for (int i = 0; i < depth; i++) {
    if (result[i] < 0) {
      result[i] += 10;
      int j = i + 1;
      for (j; result[j] < 0; j++) {
        result[j] += 9;
        i++;
      }
      result[i + 1] -= 1;
    }
  }
  HugeInt res(result, depth);
  return res;
}

HugeInt HugeInt::sum(HugeInt &b) {
  if (!negative && !b.negative) {
    return this->simple_sum(b);
  } else if (negative && b.negative) {
    HugeInt result;
    result = this->simple_sum(b);
    result.negative = true;
    return result;
  } else if (negative && !b.negative) {
    HugeInt tmp(*this);
    tmp.negative = false;
    if (tmp.compare(b) == -1) {
      return b.simple_dif(tmp);
    } else if (tmp.compare(b) == 1) {
      HugeInt result;
      result = tmp.simple_dif(b);
      result.negative = true;
      return result;
    } else {
      HugeInt result;
      result.set("0");
      return result;
    }
  } else if (!negative && b.negative) {
    HugeInt tmp(b);
    tmp.negative = false;
    if (this->compare(tmp) == 1) {
      return this->simple_dif(b);
    } else if (this->compare(tmp) == -1) {
      HugeInt result;
      result = tmp.simple_dif(*this);
      result.negative = true;
      return result;
    } else {
      HugeInt result;
      result.set("0");
      return result;
    }
  }
  return *this;
}

HugeInt HugeInt::dif(HugeInt &b) {
  if (!negative && !b.negative) {
    if (this->compare(b) == 1) {
      return this->simple_dif(b);
    } else {
      HugeInt result;
      result = b.simple_dif(*this);
      result.negative = true;
      return result;
    }
  } else if (negative && b.negative) {
    HugeInt tmp_this(*this);
    HugeInt tmp_b(b);
    tmp_this.negative = false;
    tmp_b.negative = false;
    if (tmp_this.compare(tmp_b) == -1) {
      return tmp_b.simple_dif(tmp_this);
    } else if (tmp_this.compare(tmp_b) == 1) {
      HugeInt result;
      result = tmp_this.simple_dif(tmp_b);
      result.negative = true;
      return result;
    } else {
      HugeInt result;
      result.set("0");
      return result;
    }
  } else if (negative && !b.negative) {
    HugeInt result;
    result = this->simple_sum(b);
    result.negative = true;
    return result;
  } else if (!negative && b.negative) {
    return this->simple_sum(b);
  }
  return *this;
}

// операторы

HugeInt HugeInt::operator-() const {
	HugeInt temp(*this);
  temp.negative = !temp.negative;
  return temp;
}

HugeInt operator+(HugeInt &n1, HugeInt &n2) {
  HugeInt res = n1.sum(n2);
  res.shrink_to_fit();
  return res;
}

HugeInt operator-(HugeInt &n1, HugeInt &n2) {
  HugeInt res = n1.dif(n2);
  res.shrink_to_fit();
  return res;
}

HugeInt operator*(HugeInt &n1, HugeInt &n2) {
  HugeInt temp;
  temp.negative = n1.negative != n2.negative;
  for (int i = 0; i < n1.depth; i++) {
    for (int j = 0; j < n2.depth; j++) {
      temp.number[i + j] += n1.get_digit(i) * n2.get_digit(j);
    }
  }
  temp.normalize();
  temp.shrink_to_fit();
  return temp;
}

HugeInt operator%(HugeInt &n1, HugeInt &n2) {
  if (n1 < n2) return n1;
  HugeInt a(n1), b(n2), main_sum("1");
  if (b.negative) {
    b = -b;
    a = -a;
  }
  for (HugeInt i("0"); i <= a; i = i + b) {
    main_sum++;
  }
  // cout << " main sum: " << main_sum << endl;
  HugeInt last_sum = b * main_sum;
  // cout << " last sum: " << last_sum << endl;

  if (!a.negative) {
    return a - last_sum;
  } else {
    return a + last_sum;
  }
}

void HugeInt::shrink_to_fit() {
  for (int i = 39; i > -1; i--) {
    if (number[i] != 0) {
      depth = i + 1;
      break;
    } 
  }
  if (depth == 0) depth++;
}

void HugeInt::normalize() {
  for (int i = 0; i < 40; i++) {
    if (number[i] > 9) {
      if (i == 39) cout << " [HugeInt owerflow] ";
      int carry = number[i] / 10;
      number[i + 1] += carry;
      number[i] -= carry * 10;
    }
  }
}

std::ostream& operator<<(std::ostream &out, const HugeInt &n) {
  out << n.to_str();
  return out;
}

std::istream& operator>>(std::istream &in, HugeInt &n) {
  string temp;
  in >> temp;
  n.set(temp);
  return in;
}

void HugeInt::print_full() {
  if (negative) cout << "-";
  for (int i = 39; i > -1; cout << number[i--] << " ");
  cout << endl;
}

void HugeInt::print() {
  if (negative) cout << "-";
  for (int i = depth - 1; i > -1; cout << number[i--]);
  cout << endl;
}