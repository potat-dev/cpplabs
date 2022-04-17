// Ввести целое число N. Вывести число,
// полученное из введенного инверсией каждого
// 4-го двоичного разряда (начиная с младших)

#include <stdio.h>
#include <stdlib.h>

unsigned int invert_4(unsigned int N) {
  unsigned int mask = 0b1000;
  for (int i = 0; i < 8; i++) {
    N = N ^ mask;
    mask = mask << 4;
  }
  return N;
}

int main() {
  unsigned int N;
  scanf("%u", &N);
  printf("%u", invert_4(N));
}