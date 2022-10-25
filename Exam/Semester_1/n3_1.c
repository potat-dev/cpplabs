#include <stdio.h>

void main() {
  int a = 3;
  int b = 5;

  int c1 = a < b;
  int c2 = a > b;
  int c3 = a <= b;
  int c4 = a >= b;
  int c5 = a == b;
  int c6 = a != b;

  int sum = 0;
  int i = 0;
  for (i = 0; i < 10; i++) {
    sum += i;
  }

  sum = 0;
  for (i = 0; i <= 100; i *= 2)
    sum += i;
   
  i = 0;
  sum = 0;
  while (i < 10) {
    sum += i;
    i++;
  }

  i = 0;
  sum = 0;
  do {
    sum += i;
    i++;
  } while (i < 10);
}