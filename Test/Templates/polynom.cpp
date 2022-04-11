// #include "polynom.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// typedef long long long_64;

#define llabs(x) x > 0 ? x : -x  

// как хранится 3x^2 + 4x + 5:
// k: {5, 4, 3}
// d: {1, 1, 1}
// i:  0, 1, 2
// => представляется как a*x^i/d
// n = 3 - кол-во коэффициентов (макс степень + 1)

struct polynom {
  unsigned int n;    // количество коэффициентов
  long long *koeffs; // массив коэффициентов
  long long *dividers; // массив делителей
};

// возвращает полином любой степени
polynom *new_polynom(long long *k, long long *d, unsigned int n) {
  polynom *temp = (polynom*)malloc(sizeof(polynom));
  temp->dividers = d; // = d
  temp->koeffs = k;
  temp->n = n;
  return temp;
}

// обновляет существующий полином
void upd_polynom(polynom *p, long long *k, long long *d, unsigned int n) {
  free(p->koeffs);
  free(p->dividers);
  p->koeffs = k;
  p->dividers = d;
  p->n = n;
}

// возвращает бином вида (x + a)
polynom *new_binom(long long a) {
  long long *koeffs = (long long*)malloc(2 * sizeof(long long));
  long long *dividers = (long long*)malloc(2 * sizeof(long long));
  koeffs[0] = a; koeffs[1] = 1;
  dividers[0] = 1; dividers[1] = 1;
  polynom *temp = new_polynom(koeffs, dividers, 2);
  return temp;
}

// обновляет существующий бином
void upd_binom(polynom *b, long long a) {
  b->koeffs[0] = a;
}

long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

void simplify(long long &a, long long &b) {
  long long factor = gcd(a, b);
  a /= factor; b /= factor;
}

// выполняет действие: x/y += a/b
void add_fractions(
  long long &x, long long &y,
  long long a, long long b    // второе слагаемое
) {
  // printf("%d\n", gcd(y, b));
  long long temp_x = x, temp_y = y;
  y = (temp_y * b) / gcd(temp_y, b);
  x = (temp_x) * (y / temp_y) + (a) * (y / b);
  simplify(x, y);
}

// выполняет действие: x/y += a/b * c/d
//  x      a     c
// --- += --- * ---
//  y      b     d

void add_multiply_fractions(
  long long &x, long long &y, // слагаемое
  long long a, long long b,   // первый множитель
  long long c, long long d    // второй множитель
) {
  long long ac = a * c, bd = b * d;
  simplify(ac, bd);
  // printf("%lld %lld\n", ac, bd);
  add_fractions(x, y, ac, bd);
}

// умножает два полинома и возвращает новый
polynom *multiply(polynom *a, polynom *b) {
  unsigned int max_power = a->n + b->n - 1;
  long long *koeffs = (long long*)malloc(max_power * sizeof(long long));
  long long *dividers = (long long*)malloc(max_power * sizeof(long long));
  for (int i = 0; i < max_power; i++) {
    koeffs[i] = 0;
    dividers[i] = 1;
  }

  for (int x = 0; x < a->n; x++) { 
    for (int y = 0; y < b->n; y++) {
      // koeffs[x+y] += a->koeffs[x] * b->koeffs[y];
      add_multiply_fractions(
        koeffs[x+y], dividers[x+y],
        a->koeffs[x], a->dividers[x],
        b->koeffs[y], b->dividers[y]
      );
    }
  }

  polynom *temp = new_polynom(koeffs, dividers, max_power);
  return temp;
}

// умножает два полинома и записывает в существующий
void multiply(polynom *m, polynom *a, polynom *b) {
  unsigned int max_power = a->n + b->n - 1;
  long long *koeffs = (long long*)malloc(max_power * sizeof(long long));
  long long *dividers = (long long*)malloc(max_power * sizeof(long long));
  for (int i = 0; i < max_power; i++) {
    koeffs[i] = 0;
    dividers[i] = 1;
  }

  for (int x = 0; x < a->n; x++) {
    for (int y = 0; y < b->n; y++) {
      // arr[x+y] += a->koeffs[x] * b->koeffs[y];
      add_multiply_fractions(
        koeffs[x+y], dividers[x+y],
        a->koeffs[x], a->dividers[x],
        b->koeffs[y], b->dividers[y]
      ); //! проверить, нет ли деления на ноль
    }
  }

  free(m->koeffs);
  m->koeffs = koeffs;
  m->n = max_power;
}

// красиво выводит полином на экран
void print_polynom(polynom *p) {
  printf("p(x) = ");
  char first_been = 0;
  for (int i = p->n - 1; i >= 0; i--) {
    long long k = p->koeffs[i];
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

int main_test(int argc, char const *argv[]) {
  long long x = 35;
  long long y = 89;
  long long a = 34;
  long long b = 9887;
  long long c = 432;
  long long d = 43;
  add_multiply_fractions(x, y, a, b, c, d);
  printf("%lld %lld\n", x, y); // 34335137 243180652 - correct!!
  return 0;
}