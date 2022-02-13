// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел

#include <stdio.h>
#include "snippets.c"
#include "list.c"

void main() {
  file *file = read_file("test.txt");
  list *numbers = init_list();
  list *primes = init_list();
  list *composites = init_list();

  parse_file(file, numbers);
  split_primes(numbers, primes, composites);

  print_list(numbers);
  print_list(primes);
  print_list(composites);
}