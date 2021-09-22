// Ввести строку, выяснить, нет ли повторяющихся слов, и вывести их, если они есть
// Можно считать, что все слова имеют длину ровно 3 символа

#include <stdio.h>
#include <string.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 3
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

void main() {
  char words[WORDS_LIMIT][WORDS_LEN + 1];
  char str[STR_LIMIT];
  
  fgets(str, STR_LIMIT, stdin);

  int word = 0, k = 0;
  for (int i = 0; i <= strlen(str); i++) { // тут юзать getchar()
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

  printf("Dublicates:\n");

  for (int w = 0; w <= word + 1; w++) {
    int count = 1;

    for (int i = 0; i <= word + 1; i++) {
      if (strcmp(words[i], words[w]) == 0 && strcmp(words[i], "\0") != 0 && w != i) {
        strcpy(words[i],"\0");
        count++;
      }
    }

    if (count > 1) {
      printf("%s - %d times\n", words[w], count);
    }
  }
}

// int is_char(int c) {
//   return ((65 <= c && c <= 90) || (97 <= c && c <= 122)
//      || (128 <= c && c <= 175) || (224 <= c && c <= 239)) ? 1 : 0;
// }

// int strlen(char s[]) {
//    int c = 0;
//    while (s[c] != '\0') c++;
//    return c;
// }