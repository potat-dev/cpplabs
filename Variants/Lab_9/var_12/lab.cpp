#include "lab.h"

// инвертирует каждый четвертый бит числа
unsigned int invert_4(unsigned int N) {
  unsigned int mask = 0b1000;    // начальная маска
  for (int i = 0; i < 8; i++) {  // 8 раз т.к. uint = 4 байта
    N = N ^ mask;                // инвертируем нужный бит с помощью маски
    mask = mask << 4;            // смещаем маску на следующий четвертый бит
  }
  return N;
}

// инвертирует каждый N-ый бит числа (32 bit)
unsigned int invert_every_nth(unsigned int N, unsigned int bit) {
  if (bit > 32) return N;              // сразу выводим, т.к. нет смысла
  unsigned int mask = 1 << (bit - 1);  // начальная маска
  while (mask > 0) {                   // пока не сдвинули бит маски за ее границу 
    N = N ^ mask;                      // инвертируем нужный бит с помощью маски
    if ((int) mask < 0) break;         // если достигли старшего бита - выходим
    mask = mask << bit;                // сдвигаем маску на N бит влево
  }
  return N;
}

// определяет, каждый какой бит инвертирован
unsigned int get_invert_offset(unsigned int a, unsigned int b) {
  unsigned int diff = a ^ b;            // определяем побитовую разницу
  for (int i = 0; i < 32; i++)          // проходимся по всем битам
    if ((diff >> i) & 1) return i + 1;  // если в разнице нашли единицу - возвращаем индекс
  return 0;                             // а тут ничего не нашли
}

// красивый вывод двоичного числа на экран
void print_bin(unsigned int N) {
  // проходим по всем битам в обратном порядке
  for (int i = 31; i > -1; i--)
    printf("%d", (N >> i) & 1);
}