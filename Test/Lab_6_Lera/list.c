#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *prev;
  struct node *next;
} node;

typedef struct list {
  node* head;
  node* tail;
  int size;
} list;

void init(list *list) {
  list -> head = NULL;
  list -> tail = NULL;
  list -> size = 0;
}

void push_back(list* list, int val) {
  node* temp = (node*)malloc(sizeof(node));
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

void destroy(list* list) {
  // проходим по всему списку и все заменяем на NULL
  node *curr = list->head;
  node *prev = NULL;
  while (curr == NULL) {
    prev = curr;
    curr = curr->next;
    free(prev);
  }
  list -> head = NULL;
  list -> size = 0;
  // по факту это просто init()
}

void set(list* list, int index, int val) {
  node* curr = list->head;
  int i = 0;
  while (i != index) {
    curr = curr->next;
    i++;
  }
  curr->value = val;
}

int get(list* list, int index) {
  if (index < 0 || index >= list->size) return -1;
  node* curr = list->head;
  for (int i = 0; i < index; i++) curr = curr->next;
  return curr->value;
}

void erase(list* list, node* node) {
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

int find(list* list, int val) {
  node* curr = list->head;
  int index = 0;
  while (curr != NULL) {
    if (curr->value == val) return index;
    curr = curr->next;
    index++;
  }
  return -1;
} // можно идти с конца если индекс больше середины

void print_list(list* list) {
  node* curr = list->head;
  while (curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
}