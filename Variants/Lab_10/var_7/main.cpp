// По символьным файлам с текстом (содержащим сокращения)
// и с сокращениями создать новый файл,
// где все сокращения заменены на соответствующие слова

// файл с сокращениями имеет следующий формат:
// в каждой строке по 2 слова, разделенных пробелом.
// Cлова записываются в трехмерный массив символов
// [["", ""],
//  ["", ""],
//  ["", ""]]

#include "abbrev.h"

int find_substr(char *str, char *** abbrevs, int count) {
  for (int a = 0; a < count; a++)
    if (strcmp(str, abbrevs[a][0]) == 0)
      return a;
  return -1; 
}

int main() {
  FILE *input = fopen("input.txt", "r");
  if (input == NULL)
    perror("Error opening file");

  char *text = read_file(input);
  int text_len = strlen(text);
  printf("%d\n", text_len);
  fclose(input);

  FILE *abbrev = fopen("abbrev.txt", "r");
  if (abbrev == NULL)
    perror("Error opening file");

  int lines = get_lines(abbrev);
  char *** abbrevs = read_word_pairs(abbrev);
  fclose(abbrev);

  for (int i = 0; i < lines; i++) {
    printf(
      "line %d:\nWord 1: %s (%d)\nWord 2: %s (%d)\n\n",
      i, abbrevs[i][0], strlen(abbrevs[i][0]),
      abbrevs[i][1], strlen(abbrevs[i][1]));
  }

  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
    perror("Error opening file");

  for (int i = 0; text[i]; i++) {
    int a = find_substr(text + i, abbrevs, lines);
    if (a != -1) {
      fprintf(output, "%s", abbrevs[a][1]);
      i += strlen(abbrevs[a][0]) - 1;
    } else {
      printf("- %c ", text[i]);
      fprintf(output, "%c", text[i]);
    }
    // for (int a = 0; a < lines; a++) {
    //   if (strcmp(text + i, abbrevs[a][0]) == 0) {
    //     printf("%s - at %d\n", abbrevs[a][0], i);
    //   }
    // }
  }
  fclose(output);
  printf("%s", text);
}