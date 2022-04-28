#include "sequence.h"

// подсчет количества значащих бит в числе
int count_bits(unsigned long long N) {
  int i = 2, bits = 1;
  // определяем минимальную но достаточную..
  // степень двойки (= кол-во бит)
  while (N >= i) {
    // увеличиваем количество бит
    bits += 1;
    // максимально возможное число при данном
    // количестве бит теперь в 2 раза больше
    i *= 2;
  }
  return bits;
}

// конвертация uint64 в массив бит
char *dtoab(unsigned long long N) {
  // определяем количество бит в числе
  int len = count_bits(N);
  // создаем массив для хранения бит
  char *arr = (char *)malloc((len + 1) * sizeof(char));

  // записываем биты в массив (в правильном порядке)
  // слева направо, от старшего бита к младшему
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
  char *str = dtoab(N);
  int max = 0, current = 0;

  // проходимся по всем битам числа
  for (int i = 0; str[i] != 0; i++) {
    current = str[i] == '1' ? current + 1 : 0;
    // обновляем максимальную длину
    max = current > max ? current : max;
  }
  return max;
}

// нахождение количества серий
// из единиц длинной больше 2
int count_ones_series(unsigned long long N) {
  char *str = dtoab(N);
  int count = 0, current = 0;

  for (int i = 0; str[i] != 0; i++) {
    if (str[i] == '1') {
      current++;
    } else {
      if (current > 2) count++;
      current = 0;
    }
  }
  if (current > 2) count++;
  return count;
}