// алгоритм нахождения количества единиц в двоичной записи числа
// количество итераций цикла зависит от числа двоичных разрядов числа n
// сложность: O(n)

unsigned int count_ones (unsigned long long n) {
  unsigned int w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}
