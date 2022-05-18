#include "..\hamming.h"
#include <iostream>
using namespace std;

#define N 16 // количесво бит в кодовом слове
#define D 8  // минимальное расстояние хэмминга для кодовой книги

#define FREE 0
#define BAD  1
#define USED 2

bool has_free(uint64 *arr, uint64 size) {
  for (uint64 i = 0; i < size; i++)
    if (arr[i] == FREE) return true;
  return false;
}

int main() {
  uint64 count = 0;     // счетчик слов в кодовой книге
  uint64 next_free = 0; // следующее свободное слово
  uint64 size = (uint64) 1 << N;        // максимальное количество кодовых слов
  uint64 *mark = new uint64[size];     // отметки об использовании кодовых слов
  uint64 *CodeBook = new uint64[size]; // кодовая книга
  for (uint64 i = 0; i < size; mark[i++] = CodeBook[i] = 0);

  CodeBook[count] = 0;            // выбираем первое кодовое слово
  mark[CodeBook[count++]] = USED; // отметим его в массиве пометок

  while (has_free(mark, size)) {
    for (uint64 i = 0; i < size; i++) // проходимся по всем словам
      if (mark[i] == FREE && (hamming(i, CodeBook[count - 1]) < D)) // если слово свободно и его расстояние Хэмминга меньше чем нужно
        mark[i] = BAD; // то отмечаем как неподходящее
    // выбираем следующее кодовое слово
    for (next_free = 0; mark[next_free] != FREE; next_free++);
    CodeBook[count] = next_free;    // заносим это слово в словарь
    mark[CodeBook[count++]] = USED; // отметим это слово в массиве отметок
  }

  printf("\ncode: "); // выводим кодовую книгу на экран
  for (uint64 i = 0; i < count; i++)
    cout << CodeBook[i] << " ";

  return 0;
}