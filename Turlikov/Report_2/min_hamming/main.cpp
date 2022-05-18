#include "..\hamming.h"
// #define DOP

int min_hamming(uint64* arr, int size) {
  int minim = size;
  for (uint64 a = 0; a < size; a++) {
    for (uint64 b = a + 1; b < size; b++) {
      if (arr[a] != arr[b]) {
        int hamm = count_ones(arr[a] ^ arr[b]);
        minim = hamm < minim ? hamm : minim;
      }
    }
  }
  return minim;
}

int main() {
  printf(
    "min hamming distance: %d\n",
    min_hamming(code_table, 4)
  );

  #ifdef DOP
    int max = 32;
    int count = 0;
    for (uint64 a = 0; a < max; a++) {
      for (uint64 b = a; b < max; b++) {
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
  #endif
}