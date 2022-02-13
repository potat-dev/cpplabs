// алгоритм нахождения количества единиц в двоичной записи числа
// сложность: O(1)

char arr[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

char count_ones (unsigned long long n) {
  char w = 0;
  while (n > 0) { // не может быть более 16 итераций
    w += arr[n & 15];
    n = n >> 4;
  }
  return w;
}

// ниже используется цикл for
// так по идее требовалось, но так неоптимально

// char count_ones (unsigned long long n) {
//   char w = 0;
//   for (int i = 0; i < 16; i++) {
//     w += arr[n & 15];
//     n = n >> 4;
//   }
//   return w;
// }