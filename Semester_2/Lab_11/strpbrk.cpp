#include <stdio.h>

const char* strpbrk(const char *string, const char *strCharSet) {
  char* temp = (char*) string;
  while (*temp != 0) {
    for (int i = 0; strCharSet[i] != 0; i++)
      if (*temp == strCharSet[i]) return temp;
    temp++;
  }
  return NULL;
}