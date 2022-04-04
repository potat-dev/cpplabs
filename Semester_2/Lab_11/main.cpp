// Написать функцию
// const char* strpbrk(const char *string, const char *strCharSet)
// работающую так же, как библиотечная и тестирующую программу к ней

// доп: написать strcmp

#define DOP

#include <stdio.h>
#include <stdlib.h>

#ifndef DOP
  #include "strpbrk.h"
#else
  #include "strcmp.h"
#endif


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
  #ifndef DOP
    printf("Enter string: ");
    char *str = readstr();
    printf("Enter allowed chars: ");
    char *chrs = readstr();
    printf("The first character found: %c", *strpbrk(str, chrs));
  #else
    printf("Enter string 1: ");
    char *str1 = readstr();
    printf("Enter string 2: ");
    char *str2 = readstr();
    printf("Strcmp result: %d", strcmp(str1, str2));
  #endif
}