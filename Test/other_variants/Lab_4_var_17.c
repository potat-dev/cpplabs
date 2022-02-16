// Ввести строку и слово, удалить из строки все слова,
// которые лексикографически меньше, чем введенное слово

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 30
#define WORDS_LEN 30
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

#define len(x) (sizeof(x) / sizeof((x)[0]))

int strlen(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) count++;
  return count;
}

int strcmp(const char *s1, const char *s2) {
  unsigned char c1, c2;
  while ((c1 = *s1++) == (c2 = *s2++))
    if (c1 == '\0')
      return 0;
  return c1 - c2;
}

int is_char(char c) {
  return ((65<=c && c<=90)
      ||  (97<=c && c<=122)
      || (128<=c && c<=175)
      || (224<=c && c<=239)); }

int main (int argc, char *argv[]) {
  char words[WORDS_LIMIT][WORDS_LEN + 1] = {0};
  char str[STR_LIMIT] = {0};
  char comp_word[WORDS_LEN] = {0};

  printf("Enter a string:\n");
  fgets(str, STR_LIMIT, stdin);

  printf("\nEnter word:\n");
  fgets(comp_word, WORDS_LEN, stdin);
  comp_word[strlen(comp_word)-1] = '\0'; // ставим конец слова вместо переноса строки

  printf("\nWords:\n");
  
  int word = 0, k = 0;
  for (int i = 0; i <= len(str); i++)
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
      words[word][k] = '\0';
      if (str[i] != '\n') word++; else break;
      k = 0;
    } else if (is_char(str[i])) { words[word][k] = str[i]; k++; }

  for (int w = 0; w <= word; w++) {
    if (strcmp(words[w], comp_word) < 0)
      printf("%s\n", words[w]);
  } 
}