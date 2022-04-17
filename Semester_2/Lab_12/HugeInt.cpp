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

void HugeInt::set(int n) {
  if (i >= capacity) {
    cout << "array is full" << endl;
  } else {
    array[i++] = n;
  }
}

int HugeInt::get(int n) {
  return (n >= 0 && n < capacity) ? array[n] : 0;
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

// HugeInt operator+(const HugeInt &a, const HugeInt &b) {
//   HugeInt temp("0", a.capacity > b.capacity ? a.capacity : b.capacity);
  
// }