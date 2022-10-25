// Написать функцию
// const char* strpbrk(const char *string, const char *strCharSet)
// работающую так же, как библиотечная и тестирующую программу к ней

// доп: написать strcmp

#include <stdio.h>
#include <stdlib.h>

#include "strcmp.h"

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
  s[len] = 0;
  return s;
}

int main() {
  printf("Enter string 1: ");
  char *str1 = readstr();
  printf("Enter string 2: ");
  char *str2 = readstr();
  printf("Strcmp result: %d", my_strcmp(str1, str2));
}