#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// как хранится 3x^2 + 4x + 5:
// a: {5, 4, 3}
// i:  0, 1, 2
// => представляется как a*x^i

struct polynom {
  int n; // - количество коэффициентов
  int *arr; // массив коэффициентов
};

// возвращает полином любой степени
polynom *new_polynom(int *arr, int n) {
  polynom *temp = (polynom*)malloc(sizeof(polynom));
  temp->arr = arr;
  temp->n = n;
  return temp;
}

// обновляет существующий полином
void upd_polynom(polynom *p, int *arr, int n) {
  free(p->arr);
  p->arr = arr;
  p->n = n;
}

// возвращает бином вида (x + a)
polynom *new_binom(int a) {
  int *arr = (int*)malloc(2 * sizeof(int));
  arr[0] = a; arr[1] = 1; 
  polynom *temp = new_polynom(arr, 2);
  return temp;
}

// обновляет существующий бином
void upd_binom(polynom *b, int a) {
  b->arr[0] = a;
}

// умножает два полинома и возвращает новый
polynom *multiply(polynom *a, polynom *b) {
  int max_power = a->n + b->n - 1;
  int *arr = (int*)malloc(max_power * sizeof(int));
  for (int i = 0; i < max_power; i++) arr[i] = 0;

  for (int x = 0; x < a->n; x++) {
    for (int y = 0; y < b->n; y++) {
      arr[x+y] += a->arr[x] * b->arr[y];
    }
  }

  polynom *temp = new_polynom(arr, max_power);
  return temp;
}

// умножает два полинома и записывает в существующий
void multiply(polynom *m, polynom *a, polynom *b) {
  int max_power = a->n + b->n - 1;
  int *arr = (int*)malloc(max_power * sizeof(int));
  for (int i = 0; i < max_power; i++) arr[i] = 0;

  for (int x = 0; x < a->n; x++) {
    for (int y = 0; y < b->n; y++) {
      arr[x+y] += a->arr[x] * b->arr[y];
    }
  }

  free(m->arr);
  m->arr = arr;
  m->n = max_power;
}

// красиво выводит полином на экран
void print_polynom(polynom *p) {
  printf("p(x) = ");
  int first_been = 0;
  for (int i = p->n - 1; i >= 0; i--) {
    int x = p->arr[i];
    if (!x) continue;
    if (!first_been) {
      if (x < 0) printf("-");
      first_been++;
    } else {
      printf(x > 0 ? " + " : " - ");
    }
    if (fabs(x) == 1) {
      printf(i > 1 ? "x^%d" : i ? "x" : "1", i);
    } else {
      printf(i > 1 ? "%dx^%d" : i ? "%dx" : "%d", fabs(x), i);
    }
  }
  printf("\n");
}

void print_koeffs(int *arr, int n) {
  printf("p(x) = ");
  for (int i = 0; i < n; i++) {
    printf("(x - %d)", arr[i]);
    if (i < n-1) printf(" * ");
    else printf("\n");
  }
}

void destroy(polynom *p) {
  free(p->arr);
  free(p);
}