#include <iostream>
using namespace std;

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
    for (int x = 1; x < size; x++)
      now[x] = prev[x - 1] + prev[x];
  }

  print(now, size);
}