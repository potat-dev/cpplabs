#include <stdio.h>
#include <stdlib.h>

int fact_multiply(int start, int end) {
  int temp = 1;
  for (int i = start; i <= end; i++)
    temp *= i;
  return temp;
}

int fact(int n) {
  int temp = 1;
  for (int i = 2; i <= n; i++)
    temp *= i;
  return temp;
}

int C(int n, int k) {
  if (n == k)
    return 1;
  return fact_multiply(k + 1, n) / fact(n - k);
}

int main (int argc, char *argv[]) {
  for (int i = 0; i <= 8; i++)
    printf("%d\n", C(8, i));
}