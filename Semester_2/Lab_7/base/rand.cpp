#include "rand.h"

// генерируем случайное число
int gen() {
  static int f0 = 1, f1 = 1, f2 = 1, f = 0;
  f = (f0 + f1 + f2) % NUMS;
  f0 = f1;
  f1 = f2;
  f2 = f;
  return f;
}

// красиво выводим на экран
void pretty_print(int *arr, int n, int wide) {
  int max = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] > max) max = arr[i];
  int w = max / wide;
  for (int i = 0; i < n; i++) {
    printf("%-4d| ", i);
    for (int j = 0; j < arr[i] / w; j++) printf("#");
    printf("\n");
  }
}