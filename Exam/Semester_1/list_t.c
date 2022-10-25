#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t *prev;
  struct node_t *next;
} node_t;

typedef struct list_t {
  node_t* head;
  node_t* tail; // доп задание
  size_t size;
} list_t;

void init(list_t *list) {
  list -> head = NULL;
  list -> tail = NULL;
  list -> size = 0;
}

void old_push_back(list_t* list, int val) {
  node_t* temp = (node_t*) malloc(sizeof(node_t));
  temp->value = val;
  temp->next = NULL;
  node_t* curr;
  if (list->head != NULL) {
    curr = list->head;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
  } else {
    list->head = temp;
    temp->prev = NULL;
  }
  list->size++;
}

// здесь с использованием tail
void push_back(list_t* list, int val) {
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  temp->value = val;
  temp->next = NULL;
  
  if (list->size == 0) {
    list->head = temp;
    list->tail = temp;
    temp->prev = NULL;
  } else {
    temp->prev = list->tail;
    list->tail->next = temp;
    list->tail = temp;
  }
  list->size++;
}

void destroy(list_t* list) {
  // проходим по всему списку и все заменяем на NULL
  node_t *curr = list->head;
  node_t *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr->next;
    free(prev);
  }
  list -> head = NULL;
  list -> size = 0;
  // по факту это просто init()
}


void insert(list_t* list, node_t* node, int val) {
  // еще нужно проверить, не равнво ли node != head и node != tail
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  temp->value = val;
  temp->prev = node;
  temp->next = node->next;
  node->next = temp;
  node->next->prev = temp;
  list->size++;
}

void set(list_t* list, int index, int val) {
  node_t* curr = list->head;
  int i = 0;
  while (i != index) {
    curr = curr->next;
    i++;
  }
  curr->value = val;
}

int get(list_t* list, int index) {
  if (index < 0 || index >= list->size) return -1;
  node_t* curr = list->head;
  for (int i = 0; i < index; i++) curr = curr->next;
  return curr->value;
}

void erase(list_t* list, node_t* node) {
  if (node == list->head) { // проверка на head
    list->head = list->head->next;
    if (node->next != NULL) // проверка на tail
      node->next->prev = NULL;
  } else {
    node->prev->next = node->next;
    if (node->next != NULL) // проверка на tail
      node->next->prev = node->prev;
  }
  free(node);
  list->size--;
}

int find(list_t* list, int val) {
  node_t* curr = list->head;
  int index = 0;
  while (curr != NULL) {
    if (curr->value == val) return index;
    curr = curr->next;
    index++;
  }
  return -1;
} // можно идти с конца если индекс больше середины

void print_list(list_t* list) {
  node_t* curr = list->head;
  while (curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
}

int main (int argc, char *argv[]) {
  list_t list;
  init(&list);

  for (int i = 0; i < 10; i++) old_push_back(&list, i);

  print_list(&list);
  printf("\n");

  printf("%d\n", find(&list, 8));

  set(&list, 7, 99999);
  print_list(&list);
  printf("\n");

  insert(&list, (&list)->head, 15);
  print_list(&list);
  printf("\n");

  printf("%d\n", get(&list, 8));

  print_list(&list);
  printf("\n");

  old_push_back(&list, 123);
  print_list(&list);
}