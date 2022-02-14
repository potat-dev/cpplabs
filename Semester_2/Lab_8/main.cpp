// Сортировка вставками: пусть первые k элементов упорядочены по возрастанию
// Берется (k+1)-ый элемент и размещается среди первых k так,
// чтобы упорядоченными оказались k+1 элементов.
// Этот метод применяется при k от 1 до n-1
// полезно: https://habr.com/ru/post/181271/

#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void swap(int *a, int *b) {
  *a += *b; *b = *a - *b; *a -= *b;
}

void sort(int* arr, int n) {
  for (int k = 1; k < n; k++) {
    for (int i = k; i > 0 && arr[i-1] > arr[i]; i--) {
      swap(&arr[i-1], &arr[i]);
    }
  }
}

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++) printf("%d ", arr[i]); printf("\n");

  swap(&arr[0], &arr[5]);
  for (int i = 0; i < 10; i++) printf("%d ", arr[i]); printf("\n");

  sort(arr, 10);
  for (int i = 0; i < 10; i++) printf("%d ", arr[i]); printf("\n");
}