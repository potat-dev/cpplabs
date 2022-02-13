#include <stdio.h>
#include <stdlib.h>
#include "list.c"

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
file* read_file(char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL) perror("Error opening file");

  int fsize = file_size(f);
  char *str = (char*) malloc((fsize + 1) * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  str[fsize] = 0;
  fclose(f);

  file *temp_file = (file*) malloc(sizeof(file));
  temp_file -> str = str;
  temp_file -> size = fsize;
  return temp_file;
}

void parse_file(file *file, list *list) {
  char *str = file -> str;
  int temp = 0, has_number = 0;
  
  for (int i = 0; str[i] != 0; i++) {
    if ('0' <= str[i] && str[i] <= '9') {
      temp = temp * 10 + (str[i] - 48);
      has_number = 1;
    } else if (str[i] == ' ') {
      if (has_number) {
        push_back(list, temp);
        has_number = 0;
      }
      temp = 0;
    } else continue;
  }
  if (has_number) push_back(list, temp);
}

int is_prime(int n) {
  if (n < 3) return (n == 2);
  if (~n & 1) return 0;
  for (int i = 3; i*i <= n; i += 2)
    if (n % i == 0) return 0;
  return 1;
}

void split_primes(list *src, list *primes, list *not_primes) {
  int n = 0;
  node *curr = src->head;
  for (int i = 0; i < src->size; i++) {
    n = curr->value;
    push_back(is_prime(n) ? primes : not_primes, n);
    curr = curr->next;
  }
}