// Ввести целое число N. Найти длину
// самой длинной последовательности единиц
// в его двоичном представлении

#include "sequence.h"

int main()
{
  // вводим N
  unsigned long long N;
  printf("Enter N: ");
  scanf("%llu", &N);

  printf( // выводим результат
      "%llu -> bin: %s\nMax length: %d\n",
      N, dtoab(N), count_max_ones(N));
}
