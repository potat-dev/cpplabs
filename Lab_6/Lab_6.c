// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв.
// Вывести оба списка

#include <stdio.h>
#include <stdlib.h>

void main() {
  char str[10000] = {'\0'};
  FILE *fptr;

  if ((fptr = fopen("input.txt", "r")) == NULL) {
    printf("Error! opening file");
    exit(1);
  }
  fgets(str, 10000, fptr);
  printf("text:\n%s", str);
  fclose(fptr); 
}
