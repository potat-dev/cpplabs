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
  int first_been = 0;
  for (int i = p->n-1; i >= 0; i--) {
    int x = p->arr[i];
    if (!first_been) {
      if (x == 1 || x == -1) {
        if (x > 0) {
          printf(i > 1 ? "x^%d" : i ? "x" : "1", i);
        } else {
          printf(i > 1 ? "-x^%d" : i ? "-x" : "-1", i);
        }
      } else if (x) {
        printf(i > 1 ? "%dx^%d" : i ? "%dx" : "%d", x, i);
      }
      if (x) first_been++;
    } else {
      if (x == 1 || x == -1) {
        printf(
          (x > 0) ?
          (i > 1 ? " + x^%d" : i ? " + x" : " + 1") :
          (i > 1 ? " - x^%d" : i ? " - x" : " - 1"), i
        );
      } else if (x) {
        printf(
          (x > 0) ?
          (i > 1 ? " + %dx^%d" : i ? " + %dx" : " + %d") :
          (i > 1 ? " - %dx^%d" : i ? " - %dx" : " - %d"),
          (x > 0) ? x : -x, i
        );
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

  polynom *temp = new_polynom(arr, max_power);
  return temp;
}

int main() {
  int temp = 0;
  int arr1[2] = {1, 1};
  int arr2[2] = {2, 1};
  int arr[2] = {0, 1};

  polynom *p1 = new_polynom(arr1, 2);
  polynom *p2 = new_polynom(arr2, 2);

  print_polynom(p1);
  print_polynom(p2);

  polynom *m = multiply(p1, p2);
  print_polynom(m);

  printf("\n---test---\n\n");

  int n = 0;
  printf("input n = ");
  scanf("%d", &n);
  if (n < 1) exit(42);
  printf("input %d numbers: ", n);

  scanf("%d", &temp);
  arr[0] = -temp;

  p1 = new_polynom(arr, 2);
  print_polynom(p1);

  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &temp);
    arr[0] = -temp;
    p2 = new_polynom(arr, 2);
    print_polynom(p2);
    p1 = multiply(p1, p2);
    print_polynom(p1);
  }
}
