// Написать генератор псевдослучайных чисел, равномерно распределенных
// на интервале [-5., 5.] (использовать rand()). Подсчитать частоты
// попадания в каждый из интервалов длиной 1 при выборке 500000

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define NUM 500000
#define POWER 12

#define frand() ((float)(rand())/(RAND_MAX))

// [-n ... n]
float frand_n(int n) {
  return frand() * n * 2 - n;
}

// [-n ... n] норм. распределение
// Центральная Предельная теорема
float normal_frand_n(int count, int n) {
  float sum = 0;
  for (int i = 0; i < count; i++)
    sum += frand_n(n);
  return sum / count;
}

// округление: i <= f < i+1
int round(float f) { 
  return (int)(f > 0 ? f : f - 1);
}

int main() {
  int freq[N * 2] = {0};
  for (int i = 0; i < NUM; i++)
    freq[round(normal_frand_n(POWER, N)) + N]++;

  for (int i = 0; i < N * 2; i++)
    printf("(%2d, %2d) - %d\n", i-N, i-N+1, freq[i]);
}