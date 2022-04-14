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

int main() {
  FILE *input = fopen("input.txt", "r");
  if (input == NULL)
    perror("Error opening file");

  char *text = read_file(input);
  int text_len = strlen(text);
  fclose(input);

  FILE *abbrev = fopen("abbrev.txt", "r");
  if (abbrev == NULL)
    perror("Error opening file");

  int lines = get_lines(abbrev);
  char *** abbrevs = read_word_pairs(abbrev);
  fclose(abbrev);

  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
    perror("Error opening file");

  for (int i = 0; text[i]; i++) {
    int a = find_substr(text + i, abbrevs, lines);
    if (a != -1) {
      fprintf(output, "%s", abbrevs[a][1]);
      i += strlen(abbrevs[a][0]) - 1;
    } else {
      fprintf(output, "%c", text[i]);
    }
  }

  fclose(output);
}