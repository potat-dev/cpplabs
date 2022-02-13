#include <stdio.h>

void aboba(int *a) {
  *a = 5;
}

void main() {
  int a = 0;
  printf("%d\n", a);

  aboba(&a);
  printf("%d", a);
}

