// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

// доп: обратная задача, заменить сокращения на символы
// * учитывать любой регистр

#include <stdio.h>
#include <stdlib.h>

#define W_COUNT 5

const char words[W_COUNT][7] = {
  "XCLM", "QTES", "HASH", "DLLR", "PRCNT", "AMPSND",
  "LBRCK", "RBRCK", "ASTRK", "PLUS", "MINUS", "SLSH",
  "DOT", "COMMA", "COLON", "SCLN", "ATSMB", "QSTN",
  "LARR", "EQUL", "RARR", "TILDE", "PIPE", "UNDSC"
};

const char punct[W_COUNT] = {
  '!', '"', '#', '$', '%', '&',
  '(', ')', '*', '+', "-", "/",
  '.', ',', ':', ';', '@', '?',
  '<', '=', '>', '~', '|', '_'
};

char lower(int c) {
  return c > 64 && c < 91 ? c + 32 : c;
}

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

int lenght(const char *s) {
  int count = 0;
  while (*s++ != '\0') count++;
  return count;
}


void main() {
  printf("Input string:\n");
  char *str = readstr();

  printf("\nString after replace:\n");
  
  for (int i = 0; i < len; i++) {
    int ch_flag = 1;
    for (int w = 0; w < W_COUNT; w++) {
      int flag = 0;
      for (int c = 0; c < lenght(words[w]); c++) {
        if (lower(str[i + c]) == lower(words[w][c])) flag++;
      }
      if (flag == lenght(words[w])) {
        printf("%c", punct[w]);
        i += lenght(words[w]) - 1;
        ch_flag = 0;
        break;
      }
    }
    if (ch_flag) printf("%c", str[i]);
  }
  free(str);
}