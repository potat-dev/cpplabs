#include "sequence.h"

// подсчет количества значащих бит в числе
int count_bits(unsigned long long N) {
  int i = 2, p = 1;
  // определяем минимальную но достаточную..
  // степень двойки (= кол-во бит)
  while (N >= i) {
    // увеличиваем количество бит
    p += 1; 
    // максимально возможное число при данном
    // количестве бит теперь в 2 раза больше
    i *= 2;
  }
  return p;
}

// конвертация uint64 в массив бит
char *dtoab(unsigned long long N) {
  // определяем количество бит в числе
  int len = count_bits(N);
  // создаем массив для хранения бит
  char *arr = (char *) malloc((len + 1) * sizeof(char));

  // записываем биты в массив (в правильном порядке)
  for (int i = 0; i < len; i++) {
    // записываем бит как char ('0' / '1')
    arr[len - i - 1] = '0' + (N & 1);
    // сдвигаем чтобы получить следующий бит
    N = N >> 1;
  }

  // добавляем в конец \0 и выходим
  arr[len] = 0;
  return arr;
}

// нахождение длины максимальной
// последовательности из единиц
int count_max_ones(unsigned long long N) {
  // преобразуем число в двоичную строку
  char *bin = dtoab(N);
  int max = 0, current = 0;

  // проходимся по всем битам числа
  for (int i = 0; bin[i] != 0; i++) {
    // current = bin[i] == '1' ? current + 1 : 0;
    if (bin[i] == '1') {
      current += 1;
    } else {
      current = 0;      
    }
    // обновляем максимальную длину
    // max = current > max ? current : max;
    if (current > max)
      max = current;
  }
  return max;
}