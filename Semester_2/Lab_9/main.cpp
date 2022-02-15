// Ввести n и коэффициенты a1 - an
// Вычислить и вывести коэффициенты многочлена
// p(x) = (x - a1) * (x - a2) * ... * (x - an)
// (написать функцию для умножения двух многочленов)

#include <stdio.h>
#include <stdlib.h>

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

polynom *multiply(polynom *a, polynom *b) {
  printf("polynom 1: ");
  for (int i = 0; i < a->n; i++)
    printf(i+1 == a->n ? "%d" : "%d, ", a->arr[i]);

  printf("\npolynom 2: ");
  for (int i = 0; i < b->n; i++)
    printf(i+1 == b->n ? "%d" : "%d, ", b->arr[i]);
  
  printf("\n");
  return a;
}

// как хранится 3x^2 + 4x + 5:
//   {5, 4, 3}
// i: 0, 1, 2
// => x^i
// а при умножении: x^(a+b)

int main() {
  int arr1[3] = {1, 2, 3};
  int arr2[4] = {6, 1, 8};

  polynom *p1 = new_polynom(arr1, 3);
  polynom *p2 = new_polynom(arr2, 4);

  int n = 0;
  printf("input n = ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    multiply(p1, p2);
  }
}
