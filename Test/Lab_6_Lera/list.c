#pragma once
#include <stdio.h>
#include <stdlib.h>

// list  ->  содержит указатель на начало связанного списка node
// node  ->  содержит ссылку на number и ссылки на пред/след элемент

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

list* init_list() {
  list *temp = (list*)malloc(sizeof(list));
  temp->head = NULL;
  temp->tail = NULL;
  temp->size = 0;
  return temp;
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
  node *curr = list->head;
  node *prev = NULL;
  while (curr == NULL) {
    prev = curr;
    curr = curr->next;
    free(prev);
  }
  list -> head = NULL;
  list -> size = 0;
}

void print_list(list* list) {
  node* curr = list->head;
  while (curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  printf("\n");
}