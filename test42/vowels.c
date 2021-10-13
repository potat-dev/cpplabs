#include <stdio.h>
#include <stdlib.h>

int vowels_count(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if ((str[i] == 'a')
    ||  (str[i] == 'e')
    ||  (str[i] == 'i')
    ||  (str[i] == 'o')
    ||  (str[i] == 'u')) count++;
  return count;
}

void main() {
  char *arr = "hello world";
  printf("%s - %d", arr, vowels_count(arr));
}

// void swap_words(word *w1, word *w2) {
//   struct word *tmp = w2;
//   w2 = w1; w1 = tmp;
// } // не работает