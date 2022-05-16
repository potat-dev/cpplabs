#include <stdio.h>
#include <memory.h>
#define N 25
#define D 20

#define FREE 0
#define BAD  1
#define USED 2

unsigned char count_ones(unsigned long long n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

bool has_free(unsigned long long *arr, unsigned long long size) {
  for (unsigned long long i = 0; i < size; i++)
    if (arr[i] == FREE) return true;
  return false;
}

int main() {
  unsigned long long count = 0;               // счетчик слов в кодовой книге
  unsigned long long next_free = 0;           // следующее свободное слово
  unsigned long long size = (unsigned long long)1 << N;        // максимальное количество кодовых слов
  unsigned long long *mark = new unsigned long long[size];     // отметки об использовании кодовых слов
  unsigned long long *CodeBook = new unsigned long long[size]; // кодовая книга
  for (unsigned long long i = 0; i < size; i++) {
    mark[i] = CodeBook[i] = 0;
  }

  CodeBook[count] = 0;            // выбираем первое кодовое слово
  mark[CodeBook[count++]] = USED; // отметим его в массиве пометок

  while (has_free(mark, size)) {
    // проходимся по всем словам
    for (unsigned long long i = 0; i < size; i++) {
      // если слово свободно и его расстояние Хэмминга меньше чем нужно
      if (mark[i] == FREE && (count_ones(i ^ CodeBook[count - 1]) < D)) {
        mark[i] = BAD; // то отмечаем как неподходящее
      }
      // printf("%d ", mark[i]); // выводим на экран
    }
    // printf("\n");

    // выбираем следующее кодовое слово
    for (next_free = 0; mark[next_free] != FREE; next_free++);
    CodeBook[count] = next_free;    // заносим это слово в словарь
    mark[CodeBook[count++]] = USED; // отметим это слово в массиве отметок
  }

  // выводим кодовую книгу на экран
  printf("\ncode: ");
  for (unsigned long long i = 0; i < count; i++) {
    printf("%d ", CodeBook[i]);
  }
  
  return 0;
}