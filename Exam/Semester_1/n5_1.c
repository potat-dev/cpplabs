#include <stdio.h>

void main() {
  int int_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr_2d[2][2] = {{1, 2}, {3, 4}};
  char char_arr[] = "hello world"; // строки заканчиваются числом 0

  int_arr[1] = 42;
  int_arr[15] = 42; // ошибка (выход за границу массива)
  // эта ошибка не улавливается компилятором

  for (int i = 0; i < 10; i++)
    printf("%d ", int_arr[i]);
  printf("\n");

  for (int i = 0; char_arr[i] != 0; i++)
    printf("%c", char_arr[i]);
  printf("\n");

  // ввод массива с клавиатуры
  int test_arr[10] = {0}; // зануление массива
  for (int i = 0; i < 10; i++) {
    scanf("%d", &test_arr[i]);
  }

  for (int i = 0; i < 10; i++)
    printf("%d ", test_arr[i]);
}