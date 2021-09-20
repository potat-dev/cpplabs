// Ввести строку, выяснить, нет ли повторяющихся слов, и вывести их, если они есть
// Можно считать, что все слова имеют длину ровно 3 символа

#include <stdio.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 3
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

int is_char(int c) {
  return ((65 <= c && c <= 90) || (97 <= c && c <= 122)
     || (128 <= c && c <= 175) || (224 <= c && c <= 239)) ? 1 : 0;
}

void main() {
  char str[STR_LIMIT];
  char c;
  int i = 0;

  // считываем строку вместе с пробелами --- работает!
  fgets(str, STR_LIMIT, stdin);
  // printf("%s", str);

  do {
    do {
      c = str[i++];
      if (is_char(c)) printf("%c - %d\n", c, (int)c);
    } while (is_char(c) && (c != ' '));
    if (c != '\0') printf("-- new word --\n");
  } while (c != '\0');

  // сплиттим по " " --- работает!
  // создаем массив слов
  // проверяем повторы
}