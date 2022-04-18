#include <iostream>
#include <string>
#include <vector>

#include "HugeInt.h"

using namespace std;

// конструктор
HugeInt::HugeInt(string str, int digits) {
  minus = (str[0] == '-');
  if (minus) str.erase(0, 1);
  cout << "str: " << str << endl;
  digit_count = str.length();
  capacity = digits;
  array.resize(capacity);
  for (int i = 0; i < digit_count; i++)
    array[i] = str[digit_count - i - 1] - '0';
}

void HugeInt::print() {
  printf("digits count %d, minus %d\n", digit_count, minus);
  for (int j = digit_count - 1; j >= 0; j--) {
    printf(j ? "%d, " : "%d\n", array[j]);
  }
}

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
          if (a.array[i] == b.array[i]) { continue; }
          else { return (a.array[i] > b.array[i]); }
        return false;
      } else return (a.digit_count > b.digit_count);
    } else {
      // если оба положительные
      if (a.digit_count == b.digit_count) {
        for (int i = 0; i < a.digit_count; i++)
          if (a.array[i] == b.array[i]) { continue; }
          else { return (a.array[i] < b.array[i]); }
        return false;
        // сравниваем каждую цифру
      } else return (a.digit_count < b.digit_count);
    }
  } else {
    if (a.minus) {
      // если a - отрицательное, а b - положительное
      return true; // a < b
    } else {
      // если a - положительное, а b - отрицательное
      return false; // a > b
    }
  }
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

// HugeInt operator+(const HugeInt &a, const HugeInt &b) {
//   HugeInt temp("0", a.capacity > b.capacity ? a.capacity : b.capacity);
  
// }