#include <stdio.h>

void main () {
  int a = 1;
  int b = 2;

  if (a == b) {
    printf("это неправда");
  } else if (a > b) {
    printf("это тоже неправда");
  } else if (a < b) {
    printf("вот это уже правда");
  } else {
    printf("это не выполнится");
  }

  int s = 1;
  switch (s) {
  case 0:
    printf("s = 0");
    break;
  case 1:
    printf("s = 1");
    break;
  default:
    printf("s равен чему-то другому");
    break;
  }
}