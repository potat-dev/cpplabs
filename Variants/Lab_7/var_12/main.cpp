// Написать генератор псевдослучайных чисел,
// равномерно распределенных на интервале [0., 0.5] (использовать rand()).
// Подсчитать частоты попадания в каждый из интервалов длиной 0.1 при выборке 500000

#include <stdio.h>
#include "frand.h"

#define N 500000
#define POWER 12

int main() {
  rand_init();
  int a[5] = {0};
  for (int i = 0; i < N; i++) {
    double s = frand(0.5, POWER);

    if (s < 0.1)
      a[0] += 1;
    else if (s < 0.2)
      a[1] += 1;
    else if (s < 0.3)
      a[2] += 1;
    else if (s < 0.4)
      a[3] += 1;
    else if (s <= 0.5)
      a[4] += 1;
  }

  for (int i = 0; i < 5; i++) {
    printf("a[%d] = %d\n", i, a[i]);
  }
}