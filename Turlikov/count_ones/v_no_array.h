// алгоритм нахождения количества единиц в двоичной записи числа
// количество итераций цикла зависит от числа двоичных разрядов числа n
// сложность: O(n)

unsigned char count_ones (unsigned long long n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}
