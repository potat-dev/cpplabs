#include <stdio.h>
#include <stdlib.h>

typedef struct word
{
  int len;
  char *word;
} word;

typedef struct node_t
{
  int value;
  struct node_t *prev;
  struct node_t *next;
} node_t;

typedef struct
{
  node_t *head;
  size_t size;
} list_t;

void init(list_t *l)
{
  l->head = NULL;
  l->size = 0;
}

void destroy(list_t *l)
{
  node_t *cur = l->head;
  node_t *prev = NULL;
  while (cur != NULL)
  {
    prev = cur;
    cur = cur->next;
    free(prev);
  }
}

void push_back(list_t *l, int val)
{
  node_t *n, *cur;
  n = (node_t *)malloc(sizeof(node_t));
  n->value = val;
  n->next = NULL;
  if (l->head == NULL)
  {
    n->prev = NULL;
    l->head = n;
  }
  else
  {
    cur = l->head;
    while (cur->next != NULL)
      cur = cur->next;
    cur->next = n;
    n->prev = cur;
  }
  l->size++;
}


int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}