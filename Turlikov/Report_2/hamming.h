#pragma once
#include <stdio.h>

typedef unsigned long long uint64;
typedef unsigned char uint8;

static uint64 code_table[] = {0x00, 0x0d, 0x16, 0x1b /* 0x1f */};

uint64 count_ones(uint64 n) {
  uint64 w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

uint64 coder(uint64 m) { return code_table[m]; }
uint64 channel(uint64 a, uint64 e) { return a ^ e; }
uint64 hamming(uint64 a, uint64 b) { return count_ones(a ^ b); }

uint64 decoder(uint64 m) {
  uint64 ind = 0, min = 5;
  for (uint64 i = 0; i < 4; i++) {
    uint64 d = hamming(m, code_table[i]);
    if (d < min) {
      min = d;
      ind = i;
    }
  }
  return ind;
}

void printf_bin(uint64 n) {  
  for (uint64 i = 0; i < 5; i++)
    printf("%d", (n >> (4 - i)) & 1);
}