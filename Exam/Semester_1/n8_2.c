// stdin, stdout, stderr, printf, scanf, sprintf, sscanf 

#include <stdio.h>

void main() {
  // fprintf(stdout, ...) == printf(...)
  // fscanf(stdin, ...) == scanf(...)
  // stderr - стандартный поток для ошибок

  int a = 1;
  int b = 2;
  printf("a = %d, b = %d\n", a, b);
  scanf("%d %d", &a, &b);
  printf("a = %d, b = %d\n", a, b);

  char arr[] = "6 1 8";
  int c = 0;
  sscanf(arr, "%d %d %d", &a, &b, &c);
  char arr2[20] = {0};
  sprintf(arr2, "a = %d, b = %d, c = %d", a, b, c);
  printf(arr2);
}