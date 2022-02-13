// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел

#include "snippets.c"

void main() {
  file *file = read_file("input/large.txt");
  list *numbers = parse_file(file);

  print_list(numbers);
  destroy(numbers);
}