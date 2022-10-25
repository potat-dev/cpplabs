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

#define ITERS 2000000

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
  4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
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

unsigned char count_ones_3(unsigned long long n) {
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

void benchmark(string str, unsigned char (*cum)(uint64_t)) {
  cout << endl << str << endl;
  for (int bit = 0; bit < 64; bit++) {
    int64_t n = (1LL << bit); // + rand() % (1LL << bit);
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++) cum(n);
    auto t2 = high_resolution_clock::now();
    int64_t duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "bit " << bit + 1
         << ": dur " << (double) duration / ITERS
         << " us" << endl;
  }
}

int main() {
  benchmark("func: 1", count_ones_1);
  benchmark("func: 2", count_ones_2);
  benchmark("func: 3", count_ones_3);
  benchmark("func: 4", count_ones_4);
  return 0;
}
