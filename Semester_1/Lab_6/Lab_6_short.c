#include "snippets.c"

void main() {
  file *file = read_file("input/medium.txt");
  list *words = parse_file(file);

  printf("\n--- ALPHABET SORT ---\n");
  sort_list(words, ALPHABET, NORMAL);
  print_list(words);

  printf("\n---- VOWELS SORT ----\n");
  sort_list(words, VOWELS, NORMAL);
  print_list(words); 

  destroy(words);
}

// 6 лаба в 12 строк кода...NICE 👌