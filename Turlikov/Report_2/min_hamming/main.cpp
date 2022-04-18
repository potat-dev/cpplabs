#include "hamming.h"
#include "stdio.h"

int main() {
  printf(
    "min hamming distance: %d\n",
    min_hamming(code_table, 4)
  );

  int max = 32;
  int count = 0;
  for (unsigned char a = 0; a < max; a++) {
    for (unsigned char b = a; b < max; b++) {
      if (a != b) {
        printf("\na: "); printf_bin(a);
        printf(" b: "); printf_bin(b);
        printf(" hamming: "); printf_bin(hamming(a, b));
        printf(" dif: %d", hamming(a, b));
        count += 1;
      }
    }
  }
  
  printf("\ncount: %d", count);
}