#pragma once
#include <stdio.h>

static int code_table[] = {0x00, 0x0d, 0x16, 0x1b}; //1f

int coder(int m) {
  return code_table[m];
}

int channel(int a, int e) {
  return a ^ e;
}

unsigned int count_ones(unsigned long long n) {
  unsigned int w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

int hamming(int a, int b) {
  return count_ones(a ^ b);
}

int decoder(int m) {
  int ind = 0, min = 5;
  for (int i = 0; i < 4; i++) {
    int d = hamming(m, code_table[i]);
    if (d < min) {
      min = d;
      ind = i;
    }
  }
  return ind;
}

void convertToBinary(int n) {
  if (n / 2 != 0)
    convertToBinary(n / 2);
  printf("%d", n % 2);
}