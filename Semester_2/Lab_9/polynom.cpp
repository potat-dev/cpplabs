#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "fractions.h"

#define llabs(x) x > 0 ? x : -x  

// как хранится 3x^2 + 4x + 5:
// k: {5, 4, 3}
// d: {1, 1, 1}
// i:  0, 1, 2
// => представляется как a*x^i/d
// n = 3 - кол-во коэффициентов (макс степень + 1)

struct polynom {
  unsigned int n;   // количество коэффициентов
  fraction *koeffs; // массив коэффициентов (дробей)
};

// возвращает полином любой степени
polynom *new_polynom(long long *k, unsigned int n) {
  polynom *temp = (polynom*)malloc(sizeof(polynom));
  fraction *fr = (fraction*)malloc(n * sizeof(fraction));
  for (int i = 0; i < n; i++) set_fraction(&fr[i], k[i]);
  temp->koeffs = fr; // массив дробей
  temp->n = n;
  return temp;
}

polynom *new_polynom(fraction *f, unsigned int n) {
  polynom *temp = (polynom*)malloc(sizeof(polynom));
  temp->koeffs = f; // массив дробей
  temp->n = n;
  return temp;
}

// обновляет существующий полином
void upd_polynom(polynom *p, long long *k, unsigned int n) {
  for (int i = 0; i < n; i++) set_fraction(&p->koeffs[i], k[i]);
}

// возвращает бином вида (x + a)
polynom *new_binom(long long a) {
  long long *koeffs = (long long*)malloc(2 * sizeof(long long));
  koeffs[0] = a; koeffs[1] = 1;
  polynom *temp = new_polynom(koeffs, 2);
  return temp;
}

// обновляет существующий бином
void upd_binom(polynom *p, long long a) {
  set_fraction(&p->koeffs[0], a);
}

// умножает два полинома и возвращает новый
polynom *multiply(polynom *a, polynom *b) {
  unsigned int max_power = a->n + b->n - 1;
  fraction *koeffs = (fraction*)malloc(max_power * sizeof(fraction));
  for (int i = 0; i < max_power; i++) set_fraction(&koeffs[i], 0);

  for (int x = 0; x < a->n; x++)
    for (int y = 0; y < b->n; y++)
      sum_multiply_fractions(&koeffs[x+y], &a->koeffs[x], &b->koeffs[y]);

  polynom *temp = new_polynom(koeffs, max_power);
  return temp;
}

// умножает два полинома и записывает в существующий
void multiply(polynom *m, polynom *a, polynom *b) {
  free(m->koeffs);
  free(m);
  m = multiply(a, b);
}

// красиво выводит полином на экран
// ! доработать для вывода дробей
void print_polynom(polynom *p) {
  printf("p(x) = ");
  char first_been = 0;
  for (int i = p->n - 1; i >= 0; i--) {
    long long k = (&p->koeffs[i])->koeff;
    if (!k) continue;
    if (!first_been) {
      if (k < 0) printf("-");
      first_been++;
    } else {
      printf(k > 0 ? " + " : " - ");
    }
    if (k == 1 || k == -1) {
      printf(i > 1 ? "x^%u" : i ? "x" : "1", i);
    } else {
      printf(i > 1 ? "%llu*x^%u" : i ? "%llux" : "%llu", llabs(k), i);
    }
  }
  printf("\n");
}

void print_koeffs(long long *arr, unsigned int n) {
  printf("p(x) = ");
  for (int i = 0; i < n; i++) {
    if (arr[i])
      printf(arr[i] > 0 ? "(x - %lld)" : "(x + %lld)", llabs(arr[i]));
    else
      printf("x");
    if (i < n-1) printf(" * ");
    else printf("\n");
  }
}

void destroy(polynom *p) {
  free(p->koeffs);
  free(p);
}