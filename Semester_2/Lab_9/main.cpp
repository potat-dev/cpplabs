// Ввести n и коэффициенты a1 - an
// Вычислить и вывести коэффициенты многочлена
// p(x) = (x - a1) * (x - a2) * ... * (x - an)
// (написать функцию для умножения двух многочленов)

#include <stdio.h>
#include <stdlib.h>
#include "polynom.h"

int main() {
  polynom *p1, *p2;
  int a = 0, n =0;

  printf("input n = ");
  scanf("%d", &n);
  if (n < 1) exit(1);

  printf("input %d numbers: ", n);
  int *arr = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  p1 = new_binom(arr[0]);
  for (int i = 1; i < n; i++) {
    destroy(p2);
    p2 = new_binom(arr[i]);
    p1 = multiply(p1, p2); // тут утечка памяти, потом исправить
  }
  print_polynom(p1);
}