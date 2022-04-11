#include "stdio.h"
#include "stdlib.h"

#include "global.h"

int *aboba(int x) {
  static int a = 1;
  a *= x;
  return &a;
}

int i = 42;

int main() {
  printf("%d\n%d\n", i, *aboba(10));
  int *a = aboba(10);
  *a = 30;
  printf("%d\n", *a);
  printf("%d\n%d\n", aboba2(1), a_global);
}