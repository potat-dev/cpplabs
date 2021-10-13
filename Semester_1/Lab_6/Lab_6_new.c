#include <stdio.h>
#include <stdlib.h>
// подключаем функции
#include "snippets.c"

#define REVERSE_ORDER 0

int compare_words(word *w1, word *w2, int reverse) {
  int min_size = w1->size < w2->size ? w1->size : w2->size;
  for (int i = 0; i < min_size; i++)
    if (w1->arr[i] != w2->arr[i])
      return reverse ^ (w1->arr[i] > w2->arr[i]);
  return reverse;
} // 0 - ok // 1 - need reverse

void sort_list(list *list, int reverse) {
  for (int i = 0; i < list->size; i++) {
    for (int j = i+1; j < list->size; j++) {
      struct node *node1 = get_node(list, i);
      struct node *node2 = get_node(list, j);
      if (compare_words(node1->word, node2->word, reverse))
        swap_nodes(node1, node2);
    }
  }
}

void main() {
  FILE *file;
  if ((file = fopen("input.txt", "r")) == NULL)
    { printf("Error opening file!"); exit(1); }

  fseek(file, 0, SEEK_END);
  size_t fsize = ftell(file); // get file size
  fseek(file, 0, SEEK_SET);

  char *str = (char*) malloc(fsize * sizeof(char));
  for (size_t i = 0; i < fsize; i++)
    str[i] = fgetc(file);
  fclose(file);

  list words;
  init(&words);
  parse_str(str, fsize, &words);
  free(str);

  sort_list(&words, REVERSE_ORDER);
  print_list(&words);
  destroy(&words);
}