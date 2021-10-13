#include <stdio.h>
#include <stdlib.h>
// подключаем функции
#include "snippets.c"

#define REVERSE_ORDER 0

void main() {
  FILE *file;
  if ((file = fopen("input.txt", "r")) == NULL)
    { printf("Error opening file!"); exit(1); }

  fseek(file, 0, SEEK_END);
  size_t fsize = ftell(file); // get file size
  fseek(file, 0, SEEK_SET);

  char *str = (char*) malloc(fsize * sizeof(char));
  for (size_t i = 0; i < fsize; i++)
    str[i] = fgetc(file);
  fclose(file);

  list words;
  init(&words);
  parse_str(str, fsize, &words);
  free(str);

  sort_list(&words, REVERSE_ORDER);
  print_list(&words);
  destroy(&words);
}