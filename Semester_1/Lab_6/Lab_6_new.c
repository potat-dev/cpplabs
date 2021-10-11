#include <stdio.h>
#include <stdlib.h>

// list -> содержит указатель на начало связанного списка node
// node -> содержит ссылку на word и ссылки на пред/след элемент
// word -> содержит массив char и длину/кол-во глассных в слове

typedef struct word {
  char *arr;
  int size;
  int capacity;
  int vowels; // гласные
} word;

// если структура содержит ссылку сама на себя
// то нудно эту ссылку оформлять как
// struct struct_name *point
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
  l->head = NULL;
  l->size = 0;
}

void destroy(list *l) {
  node *curr = l->head;
  word *word = NULL;
  node *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr->next;
    word = prev->word;
    free(word->arr);
    free(word);
    free(prev);
  }
}

void push_back(list *l, char *arr, size_t size, int capacity) {
  node *n, *curr;
  word *w;

  n = (node*)malloc(sizeof(node));
  w = (word*)malloc(sizeof(word));

  w->arr = arr;
  w->size = size;
  w->capacity = capacity;

  n->word = w;
  n->next = NULL;

  if(l->head == NULL) {
    n->prev = NULL;
    l->head = n;
  } else {
    curr = l->head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = n;
    n->prev = curr;
  }
  l->size++;
}

struct word *get(list *l, int i) {
  int count = 0;
  node *curr = l->head;
  word *result = curr->word;
  while (count++ != i) {
    curr = curr->next;
    result = curr->word;
  }
  return result;
};

void print_list(list *l) {
  for (size_t i = 0; i < l->size; i++) {
    word *temp = get(l, i);
    printf("%d -- %s\n", i, temp->arr);
    printf("------------------------");
  }

  node *curr = l->head;
  while (curr != NULL) {
    printf("%s\n", curr->word->arr);
    curr = curr->next;
  }
  printf("\n");
}

int is_char(int ch) {
  return (int) ((128 <= ch && ch <= 175) || (65 <= ch && ch <= 90) ||
                (224 <= ch && ch <= 239) || (97 <= ch && ch <= 122));
}

void main() {
  
}