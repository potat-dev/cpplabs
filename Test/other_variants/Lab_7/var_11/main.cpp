// Написать генератор псевдослучайных чисел, равномерно распределенных
// на интервале [-5., 5.] (использовать rand()). Подсчитать частоты
// попадания в каждый из интервалов длиной 1 при выборке 500000

#include "frand.h"

#define N 5
#define NUM 500000
#define POWER 12

int main() {
  int freq[N * 2] = {0};
  for (int i = 0; i < NUM; i++)
    freq[round(normal_frand_n(POWER, N)) + N]++;

  for (int i = 0; i < N * 2; i++)
    printf("(%2d, %2d) - %d\n", i-N, i-N+1, freq[i]);
}