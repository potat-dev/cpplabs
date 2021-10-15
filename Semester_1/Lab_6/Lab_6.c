// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв
// вывести оба списка

#include <stdio.h>
#include <stdlib.h>
#include "snippets.c"

#define ORDER NORMAL

void main() {
  FILE *file;
  if ((file = fopen("input/medium.txt", "r")) == NULL)
    { printf("Error opening file!"); exit(1); }

  fseek(file, 0, SEEK_END);
  size_t fsize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *str = (char*) malloc(fsize * sizeof(char));
  for (size_t i = 0; i < fsize; i++)
    str[i] = fgetc(file);
  fclose(file);

  list words;
  init(&words);
  parse_str(str, fsize, &words);
  free(str);

  printf("\n=== ALPHABET SORT ===");
  printf("\n---------------------\n");
  sort_list1(&words, ALPHABET, ORDER);
  print_list(&words);

  printf("\n==== VOWELS SORT ====");
  printf("\n---------------------\n");
  sort_list1(&words, VOWELS, ORDER);
  print_list(&words);  

  destroy(&words);
}