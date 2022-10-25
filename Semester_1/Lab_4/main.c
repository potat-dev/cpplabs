// Ввести строку, вывести различные слова
// вместе с количеством их появления в строке

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 30
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

#define len(x) (sizeof(x) / sizeof((x)[0]))

int is_char(char c) {
  return ((65 <= c && c <= 90) || (97 <= c && c <= 122) ||
          (128 <= c && c <= 175) || (224 <= c && c <= 239));
}

int strcmp(char s1[], char s2[]) {  // аналог функции strcmp в string.h
  for (int i = 0;; i++) {
    if (s1[i] != s2[i]) return 1;  // строки не совпадают
    if (s1[i] == '\0') return 0;   // строки совпадают
  }
}

void strcopy(char *dest, const char *src) {  // аналог функции strcpy в string.h
  char *p = dest;
  do *p++ = *src;  // колпируем каждый символ из src в dest
  while (*src++);
}

void main() {
  char words[WORDS_LIMIT][WORDS_LEN + 1] = {0};
  char str[STR_LIMIT] = {0};

  printf("Enter a string:\n");
  fgets(str, STR_LIMIT, stdin);
  printf("\nWords:\n--------\n");

  int word = 0, k = 0;
  for (int i = 0; i <= len(str); i++)
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
      words[word][k] = '\0';
      if (str[i] != '\n')
        word++;
      else
        break;
      k = 0;
    } else if (is_char(str[i])) {
      words[word][k] = str[i];
      k++;
    }

  int flag = 0;
  for (int w = 0; w <= word + 1; w++) {
    int count = 1;
    for (int i = 0; i <= word + 1; i++)
      if (strcmp(words[i], words[w]) == 0 && w != i &&
          strcmp(words[i], "\0") != 0) {
        strcopy(words[i], "\0");
        count++;
      }
    if (strcmp(words[w], "\0") != 0) printf("%s - %d times\n", words[w], count);
  }
}