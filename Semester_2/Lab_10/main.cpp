// По символьному файлу с текстом создать новый файл
// с форматированным текстом, в котором в каждой строке
// первое слово начинается с 3-ей позиции,
// а последнее заканчивается в 60-ой позиции

#include "file.h"

#define START_POS  3
#define END_POS   60

int main() {
  parse_file("input.txt", "output.txt", START_POS, END_POS);
  print_file("output.txt");
}