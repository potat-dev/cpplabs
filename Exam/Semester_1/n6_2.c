#include <stdio.h>

void test(int a) {
  return a;
}

void main() {
  int a = 0;
  scanf("%d", &a);

  switch (a)
  {
  case 1:
    int temp = 0;
    temp = test(a);
    break;
  
  default:
    break;
  }
}