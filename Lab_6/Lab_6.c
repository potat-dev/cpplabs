// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв.
// Вывести оба списка

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 1000
#define WORDS_LEN 30

int strcmp(const char *s1, const char *s2) {
  unsigned char c1, c2;
  while ((c1 = *s1++) == (c2 = *s2++)) if (c1 == '\0') return 0;
  return c1 - c2;
}

void strcopy(char *dest, const char *src) {
  char *p = dest;
  do *p++ = *src;
  while (*src++);
}


void main() {
  char words[WORDS_LIMIT][WORDS_LEN] = {'\0'};
  char word[WORDS_LEN] ={'\0'};
  int words_count = 0;
  FILE *f;

  if ((f = fopen("input.txt", "r")) == NULL)
    { printf("Error! opening file"); exit(1); }
  while (fscanf(f, "%s", words[words_count]) == 1) words_count++;

  // counting words
  int curr_word = 0;
  int counts[words_count];
  for (int w = 0; w < words_count; w++) {
    for (int i = 0; i < words_count; i++)
      if (strcmp(words[i], words[w]) == 0 && w != i && strcmp(words[i], "\0") != 0)
        strcopy(words[i], "\0");
    if (strcmp(words[w], "\0") != 0) {
      int count = 0;
      for (int c = 0; c < WORDS_LEN; c++)
        if ((words[w][c] == 'a')
        ||  (words[w][c] == 'e')
        ||  (words[w][c] == 'i')
        ||  (words[w][c] == 'o')
        ||  (words[w][c] == 'u')) count++;
      counts[curr_word] = count;
      curr_word++;
    }
  }

  curr_word = 0;
  for (int i = 0; i < words_count; i++) if (strcmp(words[i], "\0") != 0) {
    printf("%s - %d\n", words[i], counts[curr_word]);
    curr_word++;
  }
}