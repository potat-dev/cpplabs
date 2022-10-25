// Написать генератор псевдослучайных чисел по алгоритму
// f(n) = f(n-1) + f(n-2) + f(n-3) mod 211
// (начальные условия: f(0) = f(1) = f(2) = 1)
// Подсчитать частоту каждого числа при выборке 100000

#include "rand.h"

#define ITER 100000
#define WIDE 40

int main() {
  int array[NUMS] = {0};
  for (int i = 0; i < ITER; i++) array[gen()]++;
  printf("%-4s| %s\n----|-----\n", "num", "freq");
  for (int i = 0; i < NUMS; i++) printf("%-4d| %d\n", i, array[i]);
}