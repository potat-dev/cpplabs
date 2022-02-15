// Ввести n и коэффициенты a1 - an
// Вычислить и вывести коэффициенты многочлена
// p(x) = (x - a1) * (x - a2) * ... * (x - an)
// (написать функцию для умножения двух многочленов)

#include <stdio.h>
#include <stdlib.h>

// как хранится 3x^2 + 4x + 5:
//   {5, 4, 3}
// i: 0, 1, 2
// => x^i
// а при умножении: x^(a+b)

struct polynom {
  int n; // - количество коэффициентов
  int *arr; // массив коэффициентов
};

polynom *new_polynom(int *arr, int n) {
  polynom *temp = (polynom*)malloc(sizeof(polynom));
  temp->arr = arr;
  temp->n = n;
  return temp;
}

void destroy(polynom *p) {
  free(p->arr);
  free(p);
}

void print_polynom(polynom *p) {
  for (int i = p->n - 1; i >= 0; i--) {
    if (p->arr[i]) {
      if (i < 2) {
        printf(i ? "%dx + " : "%d", p->arr[i]);
      } else {
        printf("%dx^%d + ", p->arr[i], i);
      }
    }
  }
  printf("\n");
}

polynom *multiply(polynom *a, polynom *b) {
  int max_power = a->n + b->n - 1;
  int *arr = (int*)malloc(max_power * sizeof(int));
  for (int i = 0; i < max_power; i++) arr[i] = 0;

  for (int x = 0; x < a->n; x++) {
    for (int y = 0; y < b->n; y++) {
      arr[x+y] += a->arr[x] * b->arr[y];
    }
  }
  // for (int i = 0; i < max_power; i++) printf("%d ", arr[i]);
  // printf("\n");
  polynom *temp = new_polynom(arr, max_power);
  return temp;
}

int main() {
  int arr1[3] = {1, 45, 3};
  int arr2[4] = {1, 6, 1, 8};

  polynom *p1 = new_polynom(arr1, 3);
  polynom *p2 = new_polynom(arr2, 4);

  print_polynom(p1);
  print_polynom(p2);

  polynom *m = multiply(p1, p2);
  print_polynom(m);

  // int n = 0;
  // printf("input n = ");
  // scanf("%d", &n);
  // for (int i = 0; i < n; i++) {
  //   multiply(p1, p2);
  // }
}
