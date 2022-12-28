// Сортировка вставками: пусть первые k элементов упорядочены по возрастанию
// Берется (k+1)-ый элемент и размещается среди первых k так,
// чтобы упорядоченными оказались k+1 элементов.
// Этот метод применяется при k от 1 до n-1

// доп: реализовать алгоритм быстрой сортировки
// и сравнить скорость их выполнения

#include <chrono>
#include <random>

#include "sort.h"

using namespace std;
#define N 50000  // кол-во элементов
#define OUTPUT   // нужно ли принтовать массив

int main() {
  int arr[N] = {0}, temp[N] = {0};
  for (int i = 0; i < N; i++) arr[i] = rand() % (N * 10);

#ifdef OUTPUT
  printf("%-11s", "original:");
  print_arr(arr, N);
#endif

  // измряем время сортировки вставками
  for (int i = 0; i < N; i++) temp[i] = arr[i];
  auto begin = chrono::steady_clock::now();
  sort(arr, N);  // сортировка вставками
  auto end = chrono::steady_clock::now();
  auto time = chrono::duration_cast<chrono::milliseconds>(end - begin);
  printf("Sort time elapsed: %ld ms\n", time.count());

  // измряем время быстрой сортировки
  for (int i = 0; i < N; i++) temp[i] = arr[i];
  begin = chrono::steady_clock::now();
  qsort(arr, N);  // быстрая сортировка
  end = chrono::steady_clock::now();
  time = chrono::duration_cast<chrono::milliseconds>(end - begin);
  printf("qSort time elapsed: %ld ms\n", time.count());

#ifdef OUTPUT
  printf("%-11s", "sorted:");
  print_arr(arr, N);
#endif
}