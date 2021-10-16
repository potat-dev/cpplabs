// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв
// вывести оба списка

#include "snippets.c"
#define ORDER NORMAL

void main() {
  file *file = read_file("input/medium.txt");
  list *words = parse_file(file);

  printf("\n--- ALPHABET SORT ---");
  sort_list(words, ALPHABET, ORDER);
  print_list(words);

  printf("\n%d %d %d\n", find_word(words, "ultrices", 0, NORMAL),
                         find_word(words, "a", 0, NORMAL),
                         find_word(words, "a", 0, REVERSE));

  printf("\n---- VOWELS SORT ----");
  sort_list(words, VOWELS, ORDER);
  print_list(words);  

  printf("\n%d\n", find_word(words, "ultrices", 0, NORMAL));

  destroy(words);
}