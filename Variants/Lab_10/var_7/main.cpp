// По символьным файлам с текстом (содержащим сокращения)
// и с сокращениями создать новый файл,
// где все сокращения заменены на соответствующие слова.

#include "stdio.h"
#include "stdlib.h"

int file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
	int fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return fsize;
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

  int lines = 2;
  char *** abbrevs = (char ***) malloc(lines * sizeof(char **));
  for (int i = 0; i < lines; i++) {
    abbrevs[i] = (char **) malloc(2 * sizeof(char *));
  }

  while ((len = getline(&line, &size, abbrev)) != -1) {
    if (line[len - 1] == '\n') {
      line[len - 1] = 0;
      len -= 1;
    }
    printf("Retrieved line of length %d:\n", len);
    printf("%s\n", line);
  }
}