// Ввести целое число N. Вывести число,
// полученное из введенного инверсией каждого
// 4-го двоичного разряда (начиная с младших)

#include "lab.h"

int main() {
  unsigned int offset;
  printf("offset: ");
  scanf("%u", &offset);

  unsigned int in;
  printf("input: ");
  scanf("%u", &in);
  printf("bin: ");
  print_bin(in);
  printf("\n\n");

  unsigned int out = invert_every_nth(in, offset);
  printf("output: %u\nbin: ", out);
  print_bin(out);
  printf("\n\n");

  printf("dif: ");
  print_bin(in ^ out);
  printf("\noffset: %d\n", get_invert_offset(in, out));
}