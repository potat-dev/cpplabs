// Ввести целое число N. Найти длину
// самой длинной последовательности единиц
// в его двоичном представлении

#include "stdio.h"
#include "stdlib.h"

int count_bits(unsigned long long N) {
  int i = 2, p = 1;
  while (N >= i) {
    i *= 2;
    p += 1;
  }
  return p;
}

char *dtoab(unsigned long long N) {
  int len = count_bits(N);
  char *arr = (char *) malloc((len + 1) * sizeof(char));
  for (int i = 0; i < len; i++) {
    arr[len - i - 1] = '0' + (N & 1);
    N = N >> 1;
  }
  arr[len] = 0;
  return arr;
}

int count_max_ones(unsigned long long N) {
  char *bin = dtoab(N);
  int max = 0, current = 0;
  for (int i = 0; bin[i]; i++) {
    current = bin[i] == '1' ? current + 1 : 0;
    // if (bin[i] == '1') {
    //   current += 1;
    // } else {
    //   current = 0;      
    // }
    max = current > max ? current : max;
    // if (current > max)
    //   max = current;
  }
  return max;
}

int main() {
  for (int i = 0; i <= 128; i++)
    printf(
      "%d - %d - %s - %d\n",
      i, count_bits(i), dtoab(i), count_max_ones(i)
    );
}
