// Ввести 10 действительных чисел, вывести максимальное по абсолютной величине число

#include <stdio.h>
#define abs(a) (a > 0 ? a : -1 * a)

void main() {
  int n, max = 0;

  printf("Enter 10 integers:\n");
  for (int i = 0; i < 10; i++) {
    scanf("%d", &n);
    if (abs(n) > max)
      max = abs(n);
  }
  
  printf("%d", max);
}