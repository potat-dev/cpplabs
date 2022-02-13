#include <stdio.h>
#include "var_1.c"

void main () {
  unsigned int n_32 = 0;
  unsigned long long n_64 = 0;
  printf("zero 32: %d\n", count_ones(n_32));
  printf("zero 64: %d\n", count_ones(n_64));
  
  n_32 = 0xffffffff;         // 4294967295
  n_64 = 0xffffffffffffffff; // 1844674407370955161
  printf("test 32: %d\n", count_ones(n_32));
  printf("test 64: %d\n", count_ones(n_64));

  n_32 = 42; n_64 = 4242424242424242;
  printf("rand 32: %d\n", count_ones(n_32));
  printf("rand 64: %d\n", count_ones(n_64));

}