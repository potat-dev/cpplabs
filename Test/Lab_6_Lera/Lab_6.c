// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел

#include "snippets.c"

void main() {
  list *numbers;
  init(numbers);

  for (int i = 0; i < 20; i++)
    push_back(numbers, i);

  print_list(numbers);
  destroy(numbers);
}

// void test() {
//   file *file = read_file("input/large.txt");
//   list *numbers = parse_file(file);

//   print_list(numbers);
//   destroy(numbers);
// }