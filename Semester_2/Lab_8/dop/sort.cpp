#include <stdio.h>

void swap(int *a, int *b) {
  *a += *b;
  *b = *a - *b;
  *a -= *b;
}

void sort(int *arr, int n) {
  for (int k = 1; k < n; k++)
    for (int i = k; i > 0 && arr[i - 1] > arr[i]; i--)
      swap(&arr[i - 1], &arr[i]);
}

void qsort(int *arr, int n) {
  int i = 0, j = n - 1;
  int mid = arr[n / 2];

  do {
    while (arr[i] < mid) i++;
    while (arr[j] > mid) j--;

    if (i <= j) {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }

  } while (i <= j);

  if (j > 0) qsort(arr, j + 1); // левый кусок
  if (i < n) qsort(&arr[i], n - i); // правый кусок
}

void print_arr(int *arr, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}