// По символьным файлам с текстом (содержащим сокращения)
// и с сокращениями создать новый файл,
// где все сокращения заменены на соответствующие слова

// файл с сокращениями имеет следующий формат:
// в каждой строке по 2 слова, разделенных пробелом
// сдлова записываются в трехмерный массив символов
// [["", ""],
//  ["", ""],
//  ["", ""]]

#include "stdio.h"
#include "stdlib.h"

#define BASE_CAPACITY 4

int file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
	int fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return fsize;
}

int get_lines(FILE *file) {
  fseek(file, 0, SEEK_SET);
  char *line = NULL;
  int count = 0, len = 0;
  size_t size = 0;
  while ((len = getline(&line, &size, file)) != -1)
    count++;
  fseek(file, 0, SEEK_SET);
  return count;
}

char *strpbrk(const char *string, const char *strCharSet) {
  char *temp = (char *)string;
  while (*temp != 0) {
    for (int i = 0; strCharSet[i] != 0; i++)
      if (*temp == strCharSet[i])
        return temp;
    temp++;
  }
  return NULL;
}

int main() {
  FILE *input = fopen("input.txt", "r");
  FILE *abbrev = fopen("abbrev.txt", "r");
  if (input == NULL || abbrev == NULL)
    perror("Error opening file");

  int input_size = file_size(input);
  char *text = (char *) malloc(input_size * sizeof(char));
  for (int i = 0; i < input_size; i++)
    text[i] = fgetc(input);
  fclose(input);

  char *line = NULL;
  size_t size = 0;
  int len;

  int lines = get_lines(abbrev);
  printf("lines: %d\n", lines);
  char *** abbrevs = (char ***) malloc(lines * sizeof(char **));
  for (int i = 0; i < lines; i++) {
    abbrevs[i] = (char **) malloc (2 * sizeof(char *));
    abbrevs[i][0] = (char *) malloc((BASE_CAPACITY + 1) * sizeof(char));
    abbrevs[i][1] = (char *) malloc((BASE_CAPACITY + 1) * sizeof(char));
  }

  // считываем каждую строку файла
  for (int i = 0; i < lines; i++) {
    int capacity = BASE_CAPACITY, size = 0;
    // считываем первое слово
    char c = getc(abbrev);
    while (c != ' ' && c != '\n' && c != EOF) {
      size++;
      if (size > capacity) {
        capacity *= 2;
        abbrevs[i][0] = (char *) realloc(abbrevs[i][0], (capacity + 1) * sizeof(char));
      }
      abbrevs[i][0][size - 1] = c;
      c = getc(abbrev);
    }
    abbrevs[i][0][size] = 0;
    //? printf("line %d 0: %s\n", i, abbrevs[i][0]);

    // считываем второе слово
    capacity = BASE_CAPACITY, size = 0;
    c = getc(abbrev);
    while (c != ' ' && c != '\n' && c != EOF) {
      size++;
      if (size > capacity) {
        capacity *= 2;
        abbrevs[i][1] = (char *) realloc(abbrevs[i][1], (capacity + 1) * sizeof(char));
      }
      abbrevs[i][1][size - 1] = c;
      c = getc(abbrev);
    }
    abbrevs[i][1][size] = 0;
    //? printf("line %d 1: %s\n", i, abbrevs[i][1]);
  }

  for (int i = 0; i < lines; i++) {
    printf("line %d:\nWord 1: %s\nWord 2: %s\n\n", i, abbrevs[i][0], abbrevs[i][1]);
  }

  fclose(abbrev);
  fclose(input);
}