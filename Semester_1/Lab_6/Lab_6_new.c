#include <stdio.h>
#include <stdlib.h>
// подключаем файл с функциями
#include "snippets.c"

int check_alphabet(char *w1, char *w2, int size)
{
  char c1, c2;
  // printf("  (%s %s) ", w1, w2);
    for (int i = 0; i < size; i++)
    {
      if (w1[i] < w2[i]) {
        return 1;
      } else if (w1[i] > w2[i]) {
        return 0;
      }
    }
    return 0;

  // char c1, c2;
  // while ((c1 == *w1++) == (c2 = *w2++))
  //   if (c1 == '\0')
  //     return 0;
  // return 1;
}

void sort_list(list *list) { // int sort_order
	node *curr = list->head;
	// for (size_t i = 0; i < list->size; i++) {
    for (size_t j = 0; j < list->size; j++) { /// спросить Янковского за size_t
    // for (size_t j = i + 1; j < list->size; j++) {
    for (size_t i = (list->size - 1); i > j; i--) {
      struct node *node1 = get_node(list, i);
      struct node *node2 = get_node(list, i-1);
      int min_node = node1->word->size < node2->word->size ? node1->word->size : node2->word->size;
      // int need_to_sort = check_alphabet(&(node1)->word->arr, &(node2)->word->arr, min_node, 0);
      int need_to_sort = check_alphabet(node1->word->arr, node2->word->arr, min_node);
      // printf("%s %s - %d\n", node1->word->arr, node2->word->arr, need_to_sort);

      // // printf("%s %s - %d %d - %d - %d\n------------------\n\n",
      // node1->word->arr, node2->word->arr,
      // node1->word->size, node2->word->size, min_node,
      // // need_to_sort);

      if (need_to_sort) {
      // if (strcmp((&node1->word->arr), (&node2->word->arr)) > 0) {
        swap_nodes(node1, node2);
      }
    }
  }
}



void main() {
  FILE *file;
  if ((file = fopen("input.txt", "r")) == NULL) {
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

  // struct node *node1 = get_node(&words, 2);
  // struct node *node2 = get_node(&words, 3); 
  // size_t min_node = node1->word->size < node2->word->size ? node1->word->size : node2->word->size;
  // // printf("%d %d %d\n", node1->word->size,node2->word->size, min_node); 
  // printf("%d\n\n", check_alphabet(&(node1)->word->arr, &(node2)->word->arr, min_node, 1));
  
  
  sort_list(&words);
  
  // printf("%d\n\n", check_alphabet(&(node1)->word->arr, &(node2)->word->arr, min_node, 0));
  
  // if () {
  //   swap_nodes(node1, node2);
  // }

  print_list(&words);
  destroy(&words);
  fclose(file);
  free(str);
}

  // swap_nodes(get_node(&words, 0), get_node(&words, 1));

      
  // if (strcmp(&(node1)->word->arr, &(node2)->word->arr) > 0) {
  //   swap_nodes(node1, node2);
  // }

 


  