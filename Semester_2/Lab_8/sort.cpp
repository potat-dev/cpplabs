#include <stdio.h>

void swap(int *a, int *b) {
  *a += *b; *b = *a - *b; *a -= *b;
}

void sort(int *arr, int n) {
  for (int k = 1; k < n; k++) {
    for (int i = k; i > 0 && arr[i-1] > arr[i]; i--) {
      swap(&arr[i-1], &arr[i]);
    }
  }
}

void print_arr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}