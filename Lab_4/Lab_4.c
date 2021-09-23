// Ввести строку.
// Вывести различные слова вместе с количеством их появления в строке

#include <stdio.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 20
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

#define len(x) (sizeof(x) / sizeof((x)[0]))

void main() {
  char words[WORDS_LIMIT][WORDS_LEN + 1];
  char str[STR_LIMIT];
  
  printf("Input string:\n");
  fgets(str, STR_LIMIT, stdin);

  int word = 0, k = 0;
  for (int i = 0; i <= len(str); i++) { // тут юзать getchar()
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
      words[word][k] = '\0';
      if (str[i] != '\n') {
        word++;
      } else { break; }
      k = 0;
    } else {
      words[word][k] = str[i];
      k++;
    }
  }

  for (int i = 0; i <= word; i++) {
      printf("\n%s", words[i]);
  }

    // добавить подсчет слов

}
