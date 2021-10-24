#include "snippets.c"

void main() {
  file *file = read_file("input/medium.txt");
  list *words = parse_file(file);

  printf("\n---- NORMAL -----\n");
  print_list(words);

  printf("\n--- RM DPL ---\n");
  remove_duplicates(words); // bug here
  print_list(words);

  destroy(words);
}