// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

#include <stdio.h>
#include <stdlib.h>
#include "reducts.h"

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

  printf("\nString after replace:\n");
  for (int i = 0; i < len; i++) {
    int flag = 1;
    for (int c = 0; c < W_COUNT; c++) {
      if (str[i] == punct[c]) {
        printf("%s", words[c]);
        flag = 0;
      }
    }
    if (flag) printf("%c", str[i]);
  }
  free(str);
}