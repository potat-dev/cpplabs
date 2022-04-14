#pragma once

#include "stdio.h"
#include "stdlib.h"

#define BASE_CAPACITY 4

int strlen(const char *s);
int strcmp(char *s1, char *s2);
int file_size(FILE *file);
int get_lines(FILE *file);
char *strpbrk(const char *string, const char *strCharSet);

char *** read_word_pairs(FILE *file);
char *read_file(FILE *file);