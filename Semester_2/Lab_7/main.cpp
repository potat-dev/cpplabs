// Написать генератор псевдослучайных чисел по алгоритму
// f(n) = f(n-1) + f(n-2) + f(n-3) mod 211
// (начальные условия: f(0) = f(1) = f(2) = 1)
// Подсчитать частоту каждого числа при выборке 100000

// доп: центральная предельная теорема
// с ее помощью получить нормальное распределение
// полулучить Гауссовский колокол

#include "rand.h"
#define DOP 

#define ITER 100000
#define WIDE  40

// фактор сглаживания
// чем больше, тем острее Гауссовский колокол
#define DISTR_FACTOR 12

int main () {
  int array[NUMS] = {0};

#ifndef DOP

  for (int i = 0; i < ITER; i++)
    array[gen()]++;
  printf("%-4s| %s\n----|-----\n", "num", "freq");
  for (int i = 0; i < NUMS; i++)
    printf("%-4d| %d\n", i, array[i]);

#else

  for (int i = 0; i < ITER; i++)
    array[gen_normal(DISTR_FACTOR)]++;
  pretty_print(array, NUMS, WIDE);

#endif

}