#include <stdio.h>

void aboba(int *a) {
  *a = 5;
}

void main() {
  int a = 0;
  printf("%d\n", a);

  aboba(&a);
  printf("%d", a);
}

char tolower(int c) {
  // (int)a = 97, (int)A = 65
  // (a)97 - (A)65 = 32
  // therefore 32 + 65 = a
  return c > 64 && c < 91 ? c + 32 : c;
}

char toupper(int c) {
  // (int)a = 97, (int)A = 65
  // (a)97 - (A)65 = 32
  // therefore 97 - 32 = A
  return c > 96 && c < 123 ? c - 32 : c;
}