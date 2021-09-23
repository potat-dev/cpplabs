// Ввести строку.
// Вывести различные слова вместе с количеством их появления в строке

#include <stdio.h>
#include <string.h>

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

  for (int w = 0; w <= word + 1; w++) {
      int count = 1;

      for (int i = 0; i <= word + 1; i++) {
        if (strcmp(words[i], words[w]) == 0 && strcmp(words[i], "\0") != 0 && w != i) {
          strcpy(words[i],"\0");
          count++;
        }
      }
      
    printf("%s - %d times\n", words[w], count);
  }
}
