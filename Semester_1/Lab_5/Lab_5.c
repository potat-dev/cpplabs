// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

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

void print_char(char ch) {
  switch (ch) {
    // это было написано в 4:20 ночи
    // оптимизировать это говно
    case '!': printf("XCLM");   break;
    case '"': printf("QTES");   break;
    case '#': printf("HASH");   break;
    case '$': printf("DLLR");   break;
    case '%': printf("PRCNT");  break;
    case '&': printf("AMPSND"); break;
    case '(': printf("LBRCK");  break;
    case ')': printf("RBRCK");  break;
    case '*': printf("ASTRK");  break;
    case '+': printf("PLUS");   break;
    case '-': printf("MINUS");  break;
    case '/': printf("SLSH");   break;
    case '.': printf("DOT");    break;
    case ',': printf("COMMA");  break;
    case ':': printf("COLON");  break;
    case ';': printf("SCLN");   break;
    case '@': printf("ATSMB");  break;
    case '?': printf("QSTN");   break;
    case '<': printf("LARR");   break;
    case '=': printf("EQUL");   break;
    case '>': printf("RARR");   break;
    case '~': printf("TILDE");  break;
    case '|': printf("PIPE");   break;
    case '_': printf("UNDSC");  break;
    default: printf("%c", ch);  break;
  }
}

void main() {
  printf("Input string:\n");
  char *str = readstr();
  printf("\nString after replace:\n");
  for (int i = 0; i < len; i++)
    print_char(str[i]);
  free(str);
}