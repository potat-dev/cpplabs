// Написать функцию
// const char* strpbrk(const char *string, const char *strCharSet)
// работающую так же, как библиотечная и тестирующую программу к ней

#include <stdio.h>
#include <stdlib.h>

#include "strpbrk.h"

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
  printf("Enter string: ");
  char *str = readstr();
  printf("Enter allowed chars: ");
  char *chrs = readstr();
  printf("The first character found: %c", *my_strpbrk(str, chrs));
}