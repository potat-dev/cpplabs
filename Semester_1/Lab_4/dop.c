// Ввести строку
// Вывести различные слова вместе с количеством их появления в строке
// * Вывести их по алфавиту

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 30
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

#define len(x) (sizeof(x) / sizeof((x)[0]))

int strcmp(const char *s1, const char *s2) {
  unsigned char c1, c2;
  while ((c1 = *s1++) == (c2 = *s2++))
    if (c1 == '\0')
      return 0;
  return c1 - c2;
}

void strcopy(char *dest, const char *src) {
  char *p = dest;
  do *p++ = *src;
  while (*src++);
}

void main() {
  char words[WORDS_LIMIT][WORDS_LEN + 1] = {'\0'};
  char str[STR_LIMIT] = {'\0'};

  printf("Enter a string:\n");
  fgets(str, STR_LIMIT, stdin);
  printf("\nWords:\n--------\n");

  // splitting into words
  int word = 0, k = 0;
  for (int i = 0; i <= len(str); i++)
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
      words[word][k] = '\0'; word++; k = 0;
      if (str[i] == '\n') break;
    } else { words[word][k] = str[i]; k++; }

  // counting words
  int curr_w = 0, flag = 0;
  int counts[word];
  for (int w = 0; w < word; w++) {
    int count = 1;
    for (int i = 0; i < word; i++)
      if (strcmp(words[i], words[w]) == 0 && w != i && strcmp(words[i], "\0") != 0)
        { strcopy(words[i], "\0"); count++; }
    if (strcmp(words[w], "\0") != 0) counts[curr_w] = count;
    curr_w++;
  }

  // sorting arrays
  char temp[WORDS_LEN];
  int t = 0;
  for (int i = 0; i <= curr_w; i++)
    for (int j = i+1; j <= curr_w; j++)
      if (strcmp(words[i], words[j]) > 0) {
        strcopy(temp,words[i]);
        strcopy(words[i],words[j]);
        strcopy(words[j],temp);
        t = counts[i];
        counts[i] = counts[j];
        counts[j] = t;
  }

  for (int i = 0; i <= curr_w; i++)
    if (strcmp(words[i], "\0") != 0)
      printf("%s - %d times\n", words[i], counts[i]);
}