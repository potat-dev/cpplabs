#include <stdio.h>
#include <stdlib.h>

// list  ->  содержит указатель на начало связанного списка node
// node  ->  содержит ссылку на word и ссылки на пред/след элемент
// word  ->  содержит массив char и длину/кол-во глассных в слове

// если структура содержит ссылку сама на себя
// то нужно эту ссылку оформлять как struct struct_name *point

typedef struct word {
  char *arr;
  int size;
  int capacity;
  int vowels; // гласные
} word;

typedef struct node {
  struct word *word;
  struct node *prev;
  struct node *next;
} node;

typedef struct list {
  node  *head;
  size_t size;
} list;

void init(list *l) {
  l -> head = NULL;
  l -> size = 0;
}

void destroy(list *l) {
  node *curr = l -> head;
  word *word = NULL;
  node *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr -> next;
    word = prev -> word;
    free(word -> arr);
    free(word);
    free(prev);
  }
}

void push_back(list *l, char *arr, size_t size, int capacity) {
  word *w = (word*) malloc(sizeof(word));
  node *n = (node*) malloc(sizeof(node));
  node *curr;

  w -> arr = arr;
  w -> size = size;
  w -> capacity = capacity;
  n -> word = w;
  n -> next = NULL;

  if(l -> head == NULL) {
    n -> prev = NULL;
    l -> head = n;
  } else {
    curr = l -> head;
    while (curr -> next != NULL)
      curr = curr -> next;
    curr -> next = n;
    n -> prev = curr;
  }
  l -> size++;
}

void merge_lists(list *source, list *destination) {
  node *curr = source -> head;
  for (int i = 0; i < source -> size; i++) {
    word *temp_word = curr -> word;
    char *temp_str = (char*) malloc(temp_word -> size * sizeof(char));
    for (size_t i = 0; i < temp_word -> size; i++)
      temp_str[i] = temp_word -> arr[i];
    push_back(destination, temp_str,
              temp_word -> size, temp_word -> capacity);
    curr = curr -> next;
  }
}

struct word *get(list *l, int i) {
  int count = 0;
  node *curr = l -> head;
  word *result = curr -> word;
  while (count++ != i) {
    curr = curr -> next;
    result = curr -> word;
  }
  return result;
};

struct node *get_node(list *l, int i) {
  int count = 0;
  node *curr = l -> head;
  while (count++ != i)
    curr = curr -> next;
  return curr;
};

void print_list(list *l) {
  for (size_t i = 0; i < l->size; i++) {
    word *temp = get(l, i);
    printf("%d -- %s\n", i, temp->arr);
    printf("----------------------\n");
  }
}

int is_char(int ch) {
  return (int)
  ((97 <= ch && ch <= 122) ||
  (128 <= ch && ch <= 175) ||
  (224 <= ch && ch <= 239) ||
  (65  <= ch && ch <= 90));
}

int strcmp(char *s1, char *s2) {
  char c1, c2;
  while ((c1 == *s1++) == (c2 = *s2++))
    if (c1 == '\0')
      return 0;
  return c1 - c2;
}

void swap_nodes(node *n1, node *n2) {
  struct word *temp = n2 -> word;
  n2 -> word = n1 -> word;
  n1 -> word = temp;
}

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

void parse_str(char *temp, size_t size, list *list) {
  int capacity = 1, len = 0;
  char *str = (char*) malloc(sizeof(char));
  for (size_t i = 0; i < size; i++) {
    if (is_char(temp[i])) {
      str[len++] = temp[i];
      if (len >= capacity)
        str = (char*) realloc(str, (capacity *= 2) * sizeof(char));
      if (size - i == 1)
        goto last_char;
    } else {
      last_char:
      if (len) {
        str[len] = '\0';
        push_back(list, str, len, capacity);
        capacity = 1; len = 0;
        str = (char*) malloc(sizeof(char));
      }
    }
  }
}