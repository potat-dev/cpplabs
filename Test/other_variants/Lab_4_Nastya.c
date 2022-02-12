// Ввести строку
// Вывести различные слова вместе с количеством их появления в строке

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 30
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

#define ceil(x) ((x-(int)(x)) > 0 ? (int)(x+1) : (int)(x))
#define len(x) (sizeof(x) / sizeof((x)[0]))

int is_char(char c) {
    return ((65<=c && c<=90)
        ||  (97<=c && c<=122)
        || (128<=c && c<=175)
        || (224<=c && c<=239)) ? 1 : 0; }

int strcmp(char s1[], char s2[]) { // аналог функции strcmp в string.h
  for (int i = 0; ; i++) {
    if (s1[i] != s2[i]) return 1; // строки не совпадают
    if (s1[i] == '\0')  return 0; // строки совпадают
} }

void strcopy(char *dest, const char *src) { // аналог функции strcpy в string.h
  char *p = dest;
  do *p++ = *src; // колпируем каждый символ из src в dest
  while (*src++);
}

void main() {
  char words[WORDS_LIMIT][WORDS_LEN + 1] = {0};
  char str[STR_LIMIT] = {0};

  printf("Enter a string:\n");
  fgets(str, STR_LIMIT, stdin);
  printf("\nOutput:\n");

  int length = 0, k = 0;
  for (int i = 0; i <= len(str); i++)
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
      words[length][k] = '\0';
      if (str[i] != '\n') length++; else break;
      k = 0;
    } else if (is_char(str[i])) { words[length][k] = str[i]; k++; }

  for (int i = 0; i <= ceil(length / 2); i++) {
    printf("%s ", words[i]);
    if(strcmp(words[i], words[length - i]) != 0) {
      printf("%s ", words[length - i]);
    }
  }
}