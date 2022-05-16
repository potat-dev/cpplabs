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
  int count = 0;               // счетчик слов в кодовой книге
  int next_free = 0;           // следующее свободное слово
  int size = pow(2, N);        // максимальное количество кодовых слов
  int mark[size] = {FREE};     // отметки об использовании кодовых слов
  int CodeBook[size] = {FREE}; // кодовая книга

  CodeBook[count] = 0;            // выбираем первое кодовое слово
  mark[CodeBook[count++]] = USED; // отметим его в массиве пометок

  while (has_free(mark, size)) {
    // проходимся по всем словам
    for (int i = 0; i < size; i++) {
      // если слово свободно и его расстояние Хэмминга меньше чем нужно
      if (mark[i] == FREE && (count_ones(i ^ CodeBook[count - 1]) < D)) {
        mark[i] = BAD; // то отмечаем как неподходящее
      }
      printf("%d ", mark[i]); // выводим на экран
    }
    printf("\n");

    // выбираем следующее кодовое слово
    for (next_free = 0; mark[next_free] != FREE; next_free++);
    CodeBook[count] = next_free;    // заносим это слово в словарь
    mark[CodeBook[count++]] = USED; // отметим это слово в массиве отметок
  }

  // выводим кодовую книгу на экран
  printf("\ncode: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", CodeBook[i]);
  }
  
  return 0;
}