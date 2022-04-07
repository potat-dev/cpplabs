#include <iostream>
using namespace std;

unsigned long long get(unsigned long long *arr, int size, int i) {
  if (i < 0 || i >= size)
    return 0;
  else
    return arr[i];
}

void print(unsigned long long *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << endl;
}

void copy_arr(unsigned long long *arr1, unsigned long long *arr2, int size) {
  for (int i = 0; i < size; i++)
    arr1[i] = arr2[i];
}

void print_line(int line) {
  int size = line + 1;
  unsigned long long prev[size] = {0};
  unsigned long long now[size] = {0};
  now[0] = 1;

  for (int i = 1; i < size; i++) {
    copy_arr(prev, now, size);
    // заполняем новую строку треугольника
    for (int x = 0; x < size; x++)
      now[x] = get(prev, size, x - 1) + get(prev, size, x);
  }

  print(now, size);
}