// Ввести n и коэффициенты a1 - an
// Вычислить и вывести коэффициенты многочлена
// p(x) = (x - a1) * (x - a2) * ... * (x - an)
// (написать функцию для умножения двух многочленов)

// доп: нахождение k-той первообразной полученного полинома

#include <stdio.h>
#include <stdlib.h>

#include "polynom.h"

int main() {
  unsigned int n = 0;
  printf("input n = ");
  scanf("%u", &n);

  if (n < 1) {
    printf("n must be >= 1\n");
    exit(1);
  }

  printf("input %d numbers: ", n);
  long long *arr = (long long*) malloc(n * sizeof(long long));
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  print_koeffs(arr, n);
  
  polynom *p1 = new_binom(-arr[0]);
  if (n == 1) {
    print_polynom(p1);
    exit(1);
  }

  polynom *p2 = new_binom(0);
  for (int i = 1; i < n; i++) {
    upd_binom(p2, -arr[i]);
    multiply(p1, p1, p2);
  }

  print_polynom(p1);
  getchar(); getchar();
  return 0;
}