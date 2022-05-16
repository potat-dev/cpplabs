#include <stdio.h>
#include <math.h>
#define N 5
#define D 3

#define FREE 0
#define BAD  1
#define USED 2

unsigned char count_ones(unsigned char n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

bool has_free(int *arr, int size) {
  for (int i = 0; i < size; i++)
    if (arr[i] == FREE) return true;
  return false;
}

int main() {
  int count = 0;
  int next_free = 0;
  int size = pow(2, N);
  int mark[size] = {FREE};
  int CodeBook[size] = {FREE};

  CodeBook[count] = 0; // шаг 1. Выбираем первое кодовое слово
  mark[CodeBook[count++]] = USED; // Отметим взятое слово в массиве пометок

  while (has_free(mark, size)) {
    // Шаг 2. отметим все слова в кандатах на расстоянии меньше d от выбранного
    for (int i = 0; i < size; i++) {
      if (mark[i] == 0 && (count_ones(i ^ CodeBook[count - 1]) < D))
        mark[i] = BAD;
      printf("%d ", mark[i]);
    }
    printf("\n");

    // шаг 1. Выбираем второе кодовое слово
    for (next_free = 0; mark[next_free] != FREE; next_free++);
    CodeBook[count] = next_free;    // заносим это слово в словарь
    mark[CodeBook[count++]] = USED; // отметим это слово в массиве отметок
  }

  printf("code: ");
  for (int i = 0; i < count; i++)
    printf("%d ", CodeBook[i]);

  // теперь понимаю
  return 0;
}