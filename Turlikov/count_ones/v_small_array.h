// алгоритм нахождения количества единиц в двоичной записи числа
// сложность: O(1)

unsigned char arr[16] = {
  0, 1, 1, 2, 1, 2, 2, 3,
  1, 2, 2, 3, 2, 3, 3, 4
};

unsigned int count_ones (unsigned long long n) {
  unsigned int w = 0;
  while (n > 0) {
    w += arr[n & 15];
    n = n >> 4;
  }
  return w;
}