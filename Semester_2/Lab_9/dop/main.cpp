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
  printf("Enter n (number of polynomial terms) = ");
  scanf("%u", &n);
  if (n < 1) {
    printf("n must be >= 1\n");
    exit(1);
  }

  printf("Enter %d numbers: ", n);
  long long *arr = (long long *)malloc(n * sizeof(long long));
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  printf("\n");
  print_koeffs(arr, n);

  polynom *p = new_binom(-arr[0]);
  if (n == 1) {
    print_polynom("\np(x) = ", p);
    exit(1);
  }

  polynom *p2 = new_binom(0);
  for (int i = 1; i < n; i++) {
    upd_binom(p2, -arr[i]);
    p = multiply(p, p2);
  }

  print_polynom("\np(x) = ", p);

  printf("\nEnter d (integral degree) = ");
  scanf("%u", &n);
  if (!n) printf("d must be >= 0\n");
  for (int i = 0; i < n; i++) integral(p, p);  // p = ∫ p
  print_polynom("\ni(p) = ", p);
}