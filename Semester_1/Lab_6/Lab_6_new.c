#include <stdio.h>
#include <stdlib.h>
// подключаем файл с функциями
#include "snippets.c"

void sort_list(list *list, int sort_order) {
	node *curr = list->head;
	for (size_t i = 0; i < list->size; i++) {
    for (size_t j = i + 1; j < list->size; j++) {
      struct node *node1 = get_node(list, i);
      struct node *node2 = get_node(list, j);      
      if (sort_order * strcmp(node1->word->arr, node2->word->arr) > 0) {
        swap_nodes(node1, node2);
      }
    }
  }
}

void main() {
  FILE *file;
  if ((file = fopen("input_small.txt", "r")) == NULL) {
    printf("Error opening file!");
		exit(1);
  }

  // get file size
  fseek(file, 0, SEEK_END);
  size_t file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *str = (char*) malloc(file_size * sizeof(char));
  for (size_t i = 0; i < file_size; i++) {
    str[i] = fgetc(file);
  }

  list words;
  init(&words);
  parse_str(str, file_size, &words);

  sort_list(&words, 1);

  print_list(&words);
  destroy(&words);
  fclose(file);
  free(str);
}

  // swap_nodes(get_node(&words, 0), get_node(&words, 1));

  // struct node *node1 = get_node(&words, 0);
  // struct node *node2 = get_node(&words, 1);      
  // if (strcmp(&(node1)->word->arr, &(node2)->word->arr) > 0) {
  //   swap_nodes(node1, node2);
  // }

  // printf("%d\n\n", strcmp(&(node1)->word->arr, &(node2)->word->arr));