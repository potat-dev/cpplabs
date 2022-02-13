#include "strpbrk.h"

int main() {
  char *str = (char*) "test astr";
  printf("%c", *strpbrk(str, "afe"));
}