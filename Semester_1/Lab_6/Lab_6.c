// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв
// вывести оба списка

#include "snippets.c"
#define ORDER NORMAL

void main() {
  file *file = read_file("input/medium.txt");
  list *words = parse_file(file);

  printf("\n=== ALPHABET SORT ===");
  printf("\n---------------------\n");
  sort_list(words, ALPHABET, ORDER);
  print_list(words);

  printf("\n\n%d\n", find_word(words, 0, "ultrices"));

  printf("\n==== VOWELS SORT ====");
  printf("\n---------------------\n");
  sort_list(words, VOWELS, ORDER);
  print_list(words);  

  printf("\n\n%d\n", find_word(words, 0, "ultrices"));

  destroy(words);
}