#include <stdio.h>
#include <stdlib.h>

void aboba(int a) {
  int a = 42;
  float b = 4.2;
  unsigned long c = 4242424242;

  if (a == 1) {
    return a; // возвращаем переменную типа int
  } else if (a == 2) {
    return b; // возвращаем переменную типа float
  } else {
    return c; // возвращаем переменную типа unsigned long
  }
}

void aboba2(int a) {
  printf("Kruk, spasibo za nezachet");
} // ничего не возвращаем