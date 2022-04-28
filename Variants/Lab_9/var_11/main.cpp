// Ввести целое число N. Найти длину
// самой длинной последовательности единиц
// в его двоичном представлении

// доп: вывести кол во серий из единиц длинной больше 2

#include "sequence.h"

int main() {
  // вводим N
  unsigned long long N;
  printf("Enter N: ");
  scanf("%llu", &N);

  printf( // выводим результат
    "%llu -> bin: %s\nMax length: %d\n",
    N, dtoab(N), count_max_ones(N)
  );

  printf(
    "Series with length > 2: %d\n",
    count_ones_series(N)
  );
}