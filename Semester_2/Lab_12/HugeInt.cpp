#include <iostream>
#include <string>
#include <vector>

#include "HugeInt.h"

using namespace std;

// конструктор
HugeInt::HugeInt(int digits, string str) {
  digits_count = digits;
  array.resize(digits_count);
}

void HugeInt::set(int n) {
  if (i >= digits_count) {
    cout << "array is full" << endl;
  } else {
    array[i++] = n;
  }
}

int HugeInt::get(int n) {
  return (n >= 0 && n < digits_count) ? array[n] : 0;
}

void HugeInt::print() {
  for (int j = digits_count - 1; j >= 0; j--) {
    printf(j ? "%d, " : "%d\n", array[j]);
  }
}