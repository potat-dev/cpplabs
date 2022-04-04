// По символьному файлу с текстом создать новый файл
// с форматированным текстом, в котором в каждой строке
// первое слово начинается с 3-ей позиции,
// а последнее заканчивается в 60-ой позиции

// доп: удаление всех пробелов

#include "file.h"

#define START_POS 3 // начальная позиция (отступ)
#define END_POS 60  // конечная позиция (перенос строки)
#define NO_WHITESPACE true // удалять ли пробелы

int main() {
  parse_file(
    "input.txt",
    "output.txt",
    START_POS,
    END_POS,
    NO_WHITESPACE
  );
  
  print_file("output.txt");
}