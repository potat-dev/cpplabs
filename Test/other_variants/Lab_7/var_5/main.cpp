// Написать генератор псевдослучайных чисел, распределенных на интервале[0, 10).
// Подсчитать и вывести частоты попадания в каждый из единичных интервалов при выборке 100000
// использовать rand()

#include <stdio.h>
#include <stdlib.h>

#define frand() ((float)(rand())/(RAND_MAX))

float frand10() {
  float f;
  do {
    f = frand();
  } while (f >= 1);
  return f * 10;
}

int main() {
  for (int i = 0; i < 10; i++)
    printf("%d\n", (int)frand10());
}