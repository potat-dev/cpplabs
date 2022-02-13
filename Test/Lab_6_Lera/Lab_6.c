// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел

#include <stdio.h>
#include "snippets.c"
#include "list.c"

void main() {
  file *file = read_file("test.txt");
  list *numbers = (list*)malloc(sizeof(list));
  list *primes = (list*)malloc(sizeof(list));
  list *not_primes = (list*)malloc(sizeof(list));

  init(numbers);
  init(primes); init(not_primes);

  parse_file(file, numbers);
  split_primes(numbers, primes, not_primes);

  print_list(numbers);
  print_list(primes);
  print_list(not_primes);
}