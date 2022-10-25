#include <stdio.h>

void main() {
  for (int i = 0; i < 10; i++) {
    if (i == 6) break;
    printf("%d ", i);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    if (i == 6) continue;
    printf("%d ", i);
  }
  printf("\n");

  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        if ((a == 6) && (b == 1) && (c == 8)) goto exit;
        printf("%d%d%d ", a, b, c);
      }
    }
  }
  exit:
  printf("\nexit");
}