#include <iostream>
#include <string>
#include "HugeInt.h"

using namespace std;

void HugeInt::set(int n) {
  if (i >= 40) {
    cout << "array is full" << endl;
  } else {
    arr[i++] = n;
  }
}

int HugeInt::get(int n) {
  return (n >= 0 && n < 40) ? arr[n] : 0;
}

void HugeInt::print() {
  for (int j = 39; j >= 0; j--) {
    printf(j ? "%d, " : "%d\n", arr[j]);
  }
}