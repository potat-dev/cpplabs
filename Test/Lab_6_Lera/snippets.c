#include <stdio.h>
#include <stdlib.h>

typedef struct file {
  char *str;
  int size;
} file;

// определение размера файла
int file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
	int fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return fsize;
}

// чтение файла в строку
file *read_file(char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL) perror("Error opening file");

  int fsize = file_size(f);
  char *str = (char*) malloc(fsize * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  fclose(f);

  file *temp_file = (file*) malloc(sizeof(file));
  temp_file -> str = str;
  temp_file -> size = fsize;
  return temp_file;
}

typedef struct node {
  int n;
  struct node *next;
} node;

typedef struct list {
  int  size;
  node *head;
} list;

void init(list *list) {
  list -> head = NULL;
  list -> size = 0;
}

void destroy(list *list) {
  node *curr = list -> head;
  node *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr -> next;
    free(prev);
  }
}

void push_back(list *list, int n) {
  node *curr, *temp = (node*) malloc(sizeof(node));
  temp -> n = n;
  temp -> next = NULL;

  if(list -> head == NULL) {
    list -> head = temp;
  } else {
    curr = list -> head;
    while (curr -> next != NULL)
      curr = curr -> next;
    curr -> next = temp;
  }
  list -> size++;
}

void print_list(list *list) {
  node *curr = list -> head;
  while (curr) {
    printf("%d\n", curr -> n);
    curr = curr -> next;
  }
}