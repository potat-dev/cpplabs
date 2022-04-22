#include "lab.h"

unsigned int invert_4(unsigned int N) {
  unsigned int mask = 0b1000;
  for (int i = 0; i < 8; i++) {
    N = N ^ mask;
    mask = mask << 4;
  }
  return N;
}

unsigned int invert_every_nth(unsigned int N, unsigned int bit) {
  if (bit > 32) return N;
  unsigned int mask = 1 << (bit - 1);
  while (mask > 0) {
    N = (N ^ mask);
    mask = mask << bit;
  }
  return N;
}

unsigned int get_invert_offset(unsigned int a, unsigned int b) {
  unsigned int diff = a ^ b;
  for (int i = 0; i < 32; i++)
    if ((diff >> i) & 1) return i + 1;
  return 0;
}