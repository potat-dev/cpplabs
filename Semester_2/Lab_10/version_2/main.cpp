// По символьному файлу с текстом создать новый файл
// с форматированным текстом, в котором в каждой строке
// первое слово начинается с 3-ей позиции,
// а последнее заканчивается в 60-ой позиции

#include "file.h"

int main() {
  string str = read_file("input.txt");
  split_lines(str);
  write_file(str, "output.txt");
  cout << endl << str << endl;
}