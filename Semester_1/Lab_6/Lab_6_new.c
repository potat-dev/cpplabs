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


// инициализация списка
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
    free(prev);
  }
}

void push_back(list *l, const char *arr) {
  node *n, *curr;
  n = (node*)malloc(sizeof(node));
  n->word->arr = arr;
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

void print_list(list *l) {
  node *curr = l->head;
  while (curr != NULL) {
    printf("%s\n", curr->word->arr);
    curr = curr->next;
  }
  printf("\n");
}


void main() {
  list main_list;
  init(&main_list);

  char *s = (char*)malloc(10*sizeof(char));
  fgets(s, 10, stdin);

  push_back(&main_list, &s);

  s = (char*)malloc(10*sizeof(char));
  fgets(s, 10, stdin);

  push_back(&main_list, &s);

  print_list(&main_list);
  destroy(&main_list);
}