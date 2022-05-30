// Тема: Сравнение методов вычисления числа единиц в двоичном представлении числа

// TODO:
// Методично описать каждый подход к вычислению числа единиц в двоичном представлении числа
// Измерить быстродействие по времени
// Построить график зависимости времени работы от числа бит в числе для всех алгоритмов
// - алгоритм с делением
// - алгоритм с побитовыми операциями
// - алгоритм со вспомогательной таблицей

#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

#define ITERS 50000000

char arr_small[16] = {
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
};

char arr_big[256] = {
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};

unsigned char count_ones_1(unsigned long long n) {
  unsigned char w = 0;
  while (n) {
    w += n % 2;
    n = n / 2;
  }
  return w;
}

unsigned char count_ones_2(unsigned long long n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

unsigned char count_ones_3 (unsigned long long n) {
  unsigned char w = 0;
  while (n > 0) {
    w += arr_small[n & 15];
    n = n >> 4;
  }
  return w;
}

unsigned char count_ones_4(unsigned long long n) {
  unsigned char w = 0;
  while (n > 0) {
    w += arr_big[n & 255];
    n = n >> 8;
  }
  return w;
}

int main() {

  // алгоритм с делением
  cout << endl << "func: 1" << endl;
  for (int bit = 0; bit < 64; bit++) {
    int64_t n = (1LL << bit); // + rand() % (1LL << bit);
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++, count_ones_1(n));
    auto t2 = high_resolution_clock::now();
    uint64_t duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "bit: " << bit + 1;
    cout << "\tdur: " << (double) duration / ITERS << " us\n";
  }

  // алгоритм с побитовыми операциями
  cout << endl << "func: 2" << endl;
  for (int bit = 0; bit < 64; bit++) {
    int64_t n = (1LL << bit); // + rand() % (1LL << bit);
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++, count_ones_2(n));
    auto t2 = high_resolution_clock::now();
    uint64_t duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "bit: " << bit + 1;
    cout << "\tdur: " << (double) duration / ITERS << " us\n";
  }

  // алгоритм со вспомогательной таблицей (маленькой)
  cout << endl << "func: 3" << endl;
  for (int bit = 0; bit < 64; bit++) {
    int64_t n = (1LL << bit); // + rand() % (1LL << bit);
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++, count_ones_3(n));
    auto t2 = high_resolution_clock::now();
    uint64_t duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "bit: " << bit + 1;
    cout << "\tdur: " << (double) duration / ITERS << " us\n";
  }

  // алгоритм со вспомогательной таблицей (большой)
  cout << endl << "func: 4" << endl;
  for (int bit = 0; bit < 64; bit++) {
    int64_t n = (1LL << bit); // + rand() % (1LL << bit);
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++, count_ones_4(n));
    auto t2 = high_resolution_clock::now();
    uint64_t duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "bit: " << bit + 1;
    cout << "\tdur: " << (double) duration / ITERS << " us\n";
  }

  return 0;
}
