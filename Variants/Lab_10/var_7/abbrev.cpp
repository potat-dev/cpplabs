#include "abbrev.h"

int strlen(const char *s) {
  int count = 0;
  while (*s) {
    count++;
    s++;
  }
  return count;
}

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

char *** read_word_pairs(FILE *file) {
  int lines = get_lines(file);
  char *** arr = (char ***) malloc(lines * sizeof(char **));
  for (int i = 0; i < lines; i++) {
    arr[i] = (char **) malloc (2 * sizeof(char *));
    arr[i][0] = (char *) malloc((BASE_CAPACITY + 1) * sizeof(char));
    arr[i][1] = (char *) malloc((BASE_CAPACITY + 1) * sizeof(char));
  }

  // считываем каждую строку файла
  for (int i = 0; i < lines; i++) {
    int capacity = BASE_CAPACITY, size = 0;
    // считываем первое слово
    char c = getc(file);
    while (c != ' ' && c != '\n' && c != EOF) {
      size++;
      if (size > capacity) {
        capacity *= 2;
        arr[i][0] = (char *) realloc(arr[i][0], (capacity + 1) * sizeof(char));
      }
      arr[i][0][size - 1] = c;
      c = getc(file);
    }
    arr[i][0][size] = 0;

    // считываем второе слово
    capacity = BASE_CAPACITY, size = 0;
    c = getc(file);
    while (c != ' ' && c != '\n' && c != EOF) {
      size++;
      if (size > capacity) {
        capacity *= 2;
        arr[i][1] = (char *) realloc(arr[i][1], (capacity + 1) * sizeof(char));
      }
      arr[i][1][size - 1] = c;
      c = getc(file);
    }
    arr[i][1][size] = 0;
  }
  return arr;
}

char *read_file(FILE *file) {
  int input_size = file_size(file);
  char *temp = (char *) malloc(input_size * sizeof(char));
  for (int i = 0; i < input_size; i++)
    temp[i] = fgetc(file);
  return temp;
}