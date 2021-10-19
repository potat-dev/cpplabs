// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв
// вывести оба списка

#include "snippets.c"
#define ORDER NORMAL

void main() {
  file *file = read_file("input/medium.txt");
  list *words = parse_file(file);

  printf("\n--- ALPHABET SORT ---\n");
  sort_list(words, ALPHABET, ORDER);
  print_list(words);

  printf("\nultrices at %d\nfirst a %d\nlast a %d\n",
        find_word(words, "ultrices", 0, NORMAL),
        find_word(words, "a", 0, NORMAL),
        find_word(words, "a", 0, REVERSE));

  printf("\n---- VOWELS SORT ----\n");
  sort_list(words, VOWELS, ORDER);
  print_list(words);  

  printf("\nultrices at %d\nfirst a %d\nlast a %d\n",
        find_word(words, "ultrices", 0, NORMAL),
        find_word(words, "a", 0, NORMAL),
        find_word(words, "a", 0, REVERSE));
  
  char *test = "hello world";
  push_back(words, test, 16);
  printf("\n---- PUSH BACK ----\n");
  print_list(words);

  printf("\n---- REMOVE NODE ----\n");
  remove_node(words, 42);
  print_list(words);

  remove_nodes(words, 0, 42); // some bugs
  printf("\n---- REMOVE NODES ----\n");
  print_list(words);

  destroy(words);
}