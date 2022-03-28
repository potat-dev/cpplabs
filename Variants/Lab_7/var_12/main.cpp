//Написать генератор псевдослучайных чисел,
//равномерно распределенных на интервале [0., 0.5] (использовать rand()).
// Подсчитать частоты попадания в каждый из интервалов длиной 0.1 при выборке 500000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define frand() ((float)(rand()) / (RAND_MAX))

int main()
{
  srand(time(NULL));
  int a[5] = {};
  for (int i = 0; i < 50000; i++)
  {
    float s = frand() * 0.5;
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
  int summ = 0;
  for (int i = 0; i < 5; ++i)
  {
    summ += a[i];
    printf("%d \n", a[i]);
  }

  printf("S = %d", summ);
  return 0;
}