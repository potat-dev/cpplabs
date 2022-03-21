#include <stdio.h>

void test() {
  unsigned long long k = 0, raz = 0, i = 1;
  float a = 0, n = 0, C = 1;

  printf("Enter n: ");
  scanf("%f", &n);
  printf("Enten k: ");
  scanf("%d", &k);

  raz = n - k;
  while (i++ <= raz)
    C *= (a = (n - (i - 1)) / i);
  
  printf("C = %f", C);
}