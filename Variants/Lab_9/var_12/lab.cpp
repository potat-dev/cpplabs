#include "lab.h"

unsigned int invert_4(unsigned int N) {
  unsigned int mask = 0b1000;
  for (int i = 0; i < 8; i++) {
    N = N ^ mask;
    mask = mask << 4;
  }
  return N;
}