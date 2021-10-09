#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


void main (int argc, char *argv[]) {
  int a, b = 0;
  scanf("%d %d", &a, &b);

  swap(&a, &b);
  printf("%d %d", a, b);
}



