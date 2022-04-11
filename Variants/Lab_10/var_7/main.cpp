// По символьным файлам с текстом (содержащим сокращения)
// и с сокращениями создать новый файл,
// где все сокращения заменены на соответствующие слова

// файл с сокращениями имеет следующий формат:
// в каждой строке по 2 слова, разделенных пробелом
// сдлова записываются в трехмерный массив символов
// [["", ""],
//  ["", ""],
//  ["", ""]]

#include "abbrev.h"

int main() {
  FILE *input = fopen("input.txt", "r");
  if (input == NULL)
    perror("Error opening file");
  char *text = read_file(input);
  fclose(input);

  FILE *abbrev = fopen("abbrev.txt", "r");
  int lines = get_lines(abbrev);
  char *** abbrevs = read_word_pairs(abbrev);
  fclose(abbrev);

  for (int i = 0; i < lines; i++) {
    printf(
      "line %d:\nWord 1: %s (%d)\nWord 2: %s (%d)\n\n",
      i, abbrevs[i][0], strlen(abbrevs[i][0]),
      abbrevs[i][1], strlen(abbrevs[i][1]));
  }
}