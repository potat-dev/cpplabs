#include <stdio.h>

void main() {
  int a = 42;
  int* p_a = &a; // указатель на ячейку a
  // размер указателя всегда одинаков
  // те. sizeof(char*) == sizeof(int*) == sizeof(float*)

  printf("%d %d %d\n", a, p_a, *p_a);
  // 42 6422296 42 (второе число = адрес в памяти)

  int arr[] = {0, 1, 2, 3, 4, 5};
  // arr - это уже указатель на 0 элемент
  int* p_arr = arr;
  printf("%d %d ", p_arr, *p_arr); // 9683598 0
  printf("%d %d %d", *p_arr, *(p_arr+1), *(p_arr+2)); // 0 1 2
}

// arr[i] == *(arr + i)
// i[arr] == *(i + arr)
// эти записи аналогичны