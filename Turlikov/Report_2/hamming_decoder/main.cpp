#include "..\hamming.h"
#define DEBUG

int main() {
  uint8 arr[2][6] = {0};

  for (uint8 n = 1; n < 6; n++) {
    printf("\nerrors count: %d\n", n);
    for (uint8 e = 0; e < 32; e++) {
      if (count_ones(e) == n) {
        uint8 temp = 0;
        for (uint8 m = 0; m < 4; m++) {
          temp += (m == decoder(channel(coder(m), e)));
          #ifdef DEBUG
            printf(" mess: "); printf_bin(m);
            printf(" code: "); printf_bin(coder(m));
            printf(" err: "); printf_bin(e);
            printf(" chann: "); printf_bin(channel(coder(m), e));
            printf(" dec: "); printf_bin(decoder(channel(coder(m), e)));
            if (m == decoder(channel(coder(m), e))) printf(" [WOW]");
            printf("\n");
          #endif
        }
        arr[0][n - 1] += (temp == 4);
        arr[1][n - 1] += 1;
      }
    }
  }

  printf("\n");
  for (uint8 N = 1; N < 6; N++)
    printf("%d error(s): fixed %d / %d\n", N, arr[0][N - 1], arr[1][N - 1]);
}