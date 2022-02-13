#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node_word
{
  char *word;
  int length;
  struct node_word *prev;
  struct node_word *next;
} node_word;

typedef struct list_word
{
  node_word *head;
  size_t size;
} list_word;

void init_w(list_word *l)
{
  l->head = NULL;
  l->size = 0;
}

void destroy_w(list_word *l)
{
  node_word *cur = l->head;
  node_word *prev = NULL;
  while (cur != NULL)
  {
    prev = cur;
    cur = cur->next;
    free(prev);
  }
}

void push_back_w(list_word *l, char *w, int len)
{
  node_word *n, *cur;
  n = (node_word *)malloc(sizeof(node_word));
  n->word = w;
  n->next = NULL;
  n->length = len;
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

void print_w(list_word *l)
{
  node_word *cur = l->head;
  while (cur != NULL)
  {
    for (int k = 0; k < (cur->length); k++)
    {
      printf("%c", (cur->word)[k]);
    }
    cur = cur->next;
    printf(" ");
  }
  printf("\n");
}

list_word merge_w(list_word *l1, list_word *l2)
{
  list_word l;
  init_w(&l);
  node_word *cur = l1->head;
  while (cur != NULL)
  {
    push_back_w(&l, cur->word, cur->length);
    cur = cur->next;
  }
  cur = l2->head;
  while (cur != NULL)
  {
    push_back_w(&l, cur->word, cur->length);
    cur = cur->next;
  }
  return l;
}

int contain_w(node_word *n, char *a, int l)
{
  int check = 0;
  if (l <= n->length)
  {
    for (int i = 0; i <= ((n->length) - l); i++)
    {
      for (int j = 0; j < l; j++)
      {
        if (a[j] != (n->word[i + j]))
          check++;
      }
      if (check == 0)
        return 1;
      else
        check = 0;
    }
  }
  return 0;
}

void insert_w(list_word *l, node_word *n)
{
  node_word *nn = (node_word *)malloc(sizeof(node_word));
  char *a = (char *)malloc(2 * sizeof(char));
  a[0] = '|';
  a[1] = '|';
  nn->length = 2;
  nn->word = a;
  nn->next = n->next;
  nn->prev = n;
  n->next = nn;
  l->size++;
}

void change_w(list_word *l, char *a, int b)
{
  node_word *cur;
  if (l->head != NULL)
  {
    cur = l->head;
    if (contain_w(cur, a, b))
      insert_w(l, cur);
    while (cur->next != NULL)
    {
      cur = cur->next;
      if (contain_w(cur, a, b))
        insert_w(l, cur);
    }
  }
}

size_t file_size(FILE *file)
{
  fseek(file, 0, SEEK_END);
  size_t fsize = ftell(file);
  fseek(file, 0, SEEK_SET);
  return fsize;
}

int fsize = 0;
char *read_file()
{
  FILE *f = fopen("1.txt", "r");
  if (f == NULL)
  {
    perror("Error opening file");
    exit(1);
  }
  fsize = file_size(f);
  printf("%i\n", fsize);
  char *str = (char *)malloc(fsize * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  fclose(f);
  return str;
}

int main()
{
  int j = 0, h = 0;
  list_word l;
  FILE *f = fopen("1.txt", "r");
  int m = 0, length = 0;
  //char* a = (char*)malloc(100 * sizeof(char));
  char *a = read_file();
  char *read = (char *)malloc(100 * sizeof(char));
  //a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd'; a[4] = 'e'; a[5] = 'f';
  printf("%s\n", a);
  scanf("%100s", read);
  for (m = 0; m < 101; m++)
  {
    if (read[m] != '\0')
      length++;
    else
      break;
  }
  printf("%s\n", a);

  /*
    init_w(&l1);
    init_w(&l2);
    push_back_w(&l1, a, 2);
    push_back_w(&l2, a + 2, 2);
    push_back_w(&l1, a + 4, 1);
    print_w(&l1);
    print_w(&l2);
    l = merge_w(&l1, &l2);
    print_w(&l);
    */


  init_w(&l);
  printf("%d\n", fsize);
  for (int m = 0; m < fsize; m++)
  { 
    while (a[m] != ' ')
      j++;
    push_back_w(&l, a + h, j);
    h = ++j;
  }
  printf("%d\n", fsize);

  print_w(&l);
  change_w(&l, read, length);
  print_w(&l);
  //destroy_w(&l1);
  //destroy_w(&l2);
  destroy_w(&l);
  fclose(f);
}