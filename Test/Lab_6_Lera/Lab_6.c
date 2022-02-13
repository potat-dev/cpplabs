// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел
#include <stdio.h>
#include "snippets.c"
#include "list.c"

void main() {
  file *file = read_file("test.txt");
  list *numbers;

  init(numbers);
  parse_file(file, numbers);

  print_list(numbers);
  destroy(numbers);
}