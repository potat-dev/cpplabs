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