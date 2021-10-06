// Написать функцию, которая вставляет в массив элемент с заданным индексом и заданным значением
// Лишний элемент должен пропасть

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len(x) (sizeof(x) / sizeof((x)[0]))
int size;

#define ARR_INIT 2
// 0 - ввод массива пользователем 
// 1 - генерация массива {0 .. N-1}
// 2 - генерация случайного массива

void insert(int size, int *arr, int index, int value) {
  if (index >= 0 && index < size) {
    for (int i = size - 1; i > index; i--) arr[i] = arr[i - 1];
    arr[index] = value;
  } else {
    printf("Index out of range\n");
    exit(EXIT_FAILURE);
  }
}

void arr_init(int length, int* arr) {
  switch (ARR_INIT) {
    case 0:
      printf("Enter %d integers:\n", length);
      for (int i = 0; i < length; i++) scanf("%d", &arr[i]);
      printf("\n"); break;
    case 1:
      for(int i = 0; i < size; i++) arr[i] = i; break;
    case 2:
      srand(time(NULL)); // инициализируем генератор случайных чисел
      for (int i = 0; i < size; i++) arr[i] = rand() % 100; break;
    default:
      printf("Invalid Configuration\nChange ARR_INIT to correct");
      exit(EXIT_FAILURE);
  }
}

void main() {
  printf("Input array size: ");
  scanf("%d", &size); printf("\n");

  int arr[size];
  arr_init(len(arr), arr); // инициализируем массив

  printf("Original array:\n[ ");
  for(int i = 0; i < size; i++) printf("%d ", arr[i]);

  int id = 0, val = 0;
  printf("]\n\nEnter Index and Value to insert: ");
  scanf("%d %d", &id, &val);

  insert(len(arr), arr, id, val); // используем функцию

  printf("\nArray after insert:\n[ ");
  for(int i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("]\n");
}