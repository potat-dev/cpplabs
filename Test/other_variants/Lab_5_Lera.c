// Ввести строку и слово.
// Вывести только те слова, начало которых совпадает с введенным словом.

// Последовательно выделять слова из входной строки и формировать из них массив строк.
// Допущений о максимальном количестве слов, максимальной длине одного слова делать нельзя.

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x) / sizeof((x)[0]))

int len = 0;
char *readstr() {
  len = 0;
  int capacity = 1;
  char *s = (char *)malloc(sizeof(char));
  char c = getchar();
  while (c != '\n') {
    s[(len)++] = c;
    if (len >= capacity) {
      capacity *= 2;
      s = (char *)realloc(s, capacity * sizeof(char));
    }
    c = getchar();
  }
  s[len] = '\0';
  return s;
}


void main() {
  printf("Input string:\n");
  char *str = readstr();





  printf("\nStr:\n");
  for (int i = 0; i < len; i++) {}

  printf("%s", str);
  free(str);
}

// hello world potato world test world world lol kek world rule the world test