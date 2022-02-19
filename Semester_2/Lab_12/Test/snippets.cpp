#include <iostream>
#include <string>
#include "snippets.h"

using namespace std;

void HugeInt::print() {
  for (char i = 0; i < 5; i++)
    printf(i < 4 ? "%d, " : "%d", arr[i]);
  printf("\ntest: %d\n", test);
}

void HugeInt::set(int *a) {
  for (char i = 0; i < 5; i++) arr[i] = a[i];
}

void Test::print() {
  for (char i = 0; i < 5; i++)
    printf(i < 4 ? "%d, " : "%d", arr[i]);
  printf("\ntest: %d\n", test);
}