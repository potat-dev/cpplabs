#include <iostream>
using namespace std;

uint64_t c_ (uint16_t n, uint16_t k) {
  if (n == 0 || n < k) return 0;
  if (k == 0 || n == k) return 1;
  if (k == 1 || k == n - 1) return n;

  uint16_t nums = (n - k > k ? k : n - k); // min (k, n - k)

  // числитель
  uint64_t numerator = 1;
  for (uint16_t i = 0; i < nums; i++)
    numerator *= n - i;
  
  // знаминатель
  uint64_t denominator = 1;
  for (uint16_t i = 2; i <= nums; i++)
    denominator *= i;
  
  // cout << "= " << numerator << " / " << denominator << endl;
  return numerator / denominator;
}

// более упрощенный код
unsigned long long simple_c (unsigned int n, unsigned int k) {
  // базовые случаи которые можно не вычислять
  if (n == 0 || n < k) return 0;
  if (k == 0 || n == k) return 1;
  if (k == 1 || k == n - 1) return n;

  // вычисляем количество перемножаемых элементов
  // и в числителе и в знаменателе
  unsigned int lenght;
  if (n - k > k) {
    lenght = k;
  } else {
    lenght = n - k;
  }

  // перемножаем числа в числителе
  unsigned long long numerator = 1;
  for (unsigned int i = 0; i < lenght; i++) {
    numerator *= n - i;
  }
  
  // перемножаем числа в знаминателе
  unsigned long long denominator = 1;
  for (unsigned int i = 2; i <= lenght; i++) {
    denominator *= i;
  }
  
  // делим числитель на знаменатель
  return numerator / denominator;
}

long double c (unsigned int n, unsigned int k) {
  // базовые случаи которые можно не вычислять
  if (n == 0 || n < k) return 0;
  if (k == 0 || n == k) return 1;
  if (k == 1 || k == n - 1) return n;

  // вычисляем количество перемножаемых элементов
  // и в числителе и в знаменателе
  unsigned int lenght;
  if (n - k > k) {
    lenght = k;
  } else {
    lenght = n - k;
  }

  // перемножаем числа в числителе
  unsigned long long numerator = 1;
  for (unsigned int i = 0; i < lenght; i++) {
    numerator *= (n - i);
  }
  
  // перемножаем числа в знаминателе
  unsigned long long denominator = 1;
  for (unsigned int i = 2; i <= lenght; i++) {
    denominator *= i;
  }
  
  // делим числитель на знаменатель
  return numerator / denominator;
}


int main1() {
  cout << "c(9,  7) = " << c(9,  7) << endl; // 36
  cout << "c(6,  3) = " << c(6,  3) << endl; // 20
  cout << "c(10, 5) = " << c(10, 5) << endl; // 252
  cout << "c(0,  7) = " << c(0,  7) << endl; // 0
  cout << "c(0,  0) = " << c(0,  0) << endl; // 0
  cout << "c(9,  1) = " << c(9,  1) << endl; // 9
  cout << "c(7,  6) = " << c(7,  6) << endl; // 7
  cout << "c(18, 6) = " << c(18, 6) << endl; // 18564
}