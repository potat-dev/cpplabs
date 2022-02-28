#pragma once

#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ! потом заменить это на string
typedef struct file {
  char *str;
  int size;
} file;

int file_size(FILE *file);
file *read_file(const char *path);