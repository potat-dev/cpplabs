#include "hamming.h"

int main() {
  int arr[2][6] = {0};

  for (int n = 0; n < 6; n++) {
    for (int e = 0; e < 32; e++) {
      if (count_ones(e) == n) {
        int temp = 0;
        for (int m = 0; m < 4; m++)
          temp += (m == decoder(channel(coder(m), e)));
        arr[0][n - 1] += (temp == 4);
        arr[1][n - 1] += 1;
      }
    }
  }

  for (int N = 1; N < 6; N++)
    printf("%d error(s): fixed %d / %d\n", N, arr[0][N - 1], arr[1][N - 1]);
}