// Написать генератор псевдослучайных чисел, равномерно распределенных
// на интервале [-5., 5.] (использовать rand()). Подсчитать частоты
// попадания в каждый из интервалов длиной 1 при выборке 500000

#include <stdio.h>
#include <stdlib.h>

#define frand() ((float)(rand())/(RAND_MAX))

float frand5() {
  return frand() * 10 - 5;
}

int main() {
  for (int i = 0; i < 20; i++) {
    printf("%f\n", frand5());
  }
}