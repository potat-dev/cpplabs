// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

#include <stdio.h>
#include <stdlib.h>

// #define lower(ch) ((65 <= ch) && (ch >= 90)) ? ch : ch+32
// not working
char lower(char ch) {
  if ((65 <= ch) && (ch >= 90)) {
    return ch + 32;
  } else {
    return ch;
  }
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

#define W_COUNT 5
const char words[W_COUNT][6] = {"DOT", "COMMA", "EXCLM", "QSTN", "COLON"};
const char punct[W_COUNT] = {'.', ',', '!', '?', ':'};

void main() {
  printf("Input string:\n");
  char *str = readstr();

  printf("\nString after replace:\n");
  
  for (int i = 0; i < len; i++) {
    int ch_flag = 1;
    for (int w = 0; w < W_COUNT; w++) {
      int flag = 0;
      for (int c = 0; c < lenght(words[w]); c++) {
        if (str[i + c] == words[w][c]) flag++;
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