#include <stdio.h>
#include <stdlib.h>
#include "snippets.c"

#define ORDER NORMAL

void main() {
  FILE *file;
  if ((file = fopen("input/large.txt", "r")) == NULL)
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

  printf("\n----- ALPHABET SORT -----\n\n");
  sort_list(&words, ALPHABET, ORDER);
  print_list(&words);

  printf("\n------ VOWELS SORT ------\n\n");
  sort_list(&words, VOWELS, ORDER);
  print_list(&words);

  destroy(&words);
}