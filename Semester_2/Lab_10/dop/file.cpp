#include "file.h"

#include <stdio.h>

// форматируем файл с отступами
void parse_file(const char *in, const char *out, int start, int end,
                bool no_whitespace) {
  FILE *input = fopen(in, "rt");
  FILE *output = fopen(out, "w");
  if (input == NULL) return;

  int counter = 1;
  char c = fgetc(input);
  while (c != EOF) {
    while (counter < start) {
      fprintf(output, " ");
      counter++;
    }

    while (counter == start && c == ' ') c = fgetc(input);

    if (counter <= end) {
      fprintf(output, "%c", c);
      do {
        c = fgetc(input);
      } while ((c == ' ' || c == '\t') && no_whitespace);
      counter++;
    } else {
      fprintf(output, "\n");
      counter = 1;
    }
  }

  fclose(input);
  fclose(output);
}

// выводим файл
void print_file(const char *path) {
  FILE *file = fopen(path, "rt");
  if (file == NULL) {
    printf("failed to open file\n");
    return;
  }

  printf("\n");
  char c = fgetc(file);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(file);
  }

  printf("\n");
  fclose(file);
}