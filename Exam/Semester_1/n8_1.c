#include <stdlib.h>
#include <stdio.h>

void main() {
  char arr[100] = {0};
  int i = 0;

  FILE *fin = fopen("test.txt", "r");
  if (ferror(fin))
    printf("ошибка открытия текстового файла");

  while (!feof(fin)) {
    char c = 0;
    if (fscanf(fin, "%c", &c))
      arr[i++] = c;
  }
  printf("%s", arr);
  fclose(fin);

  FILE *fout = fopen("output.txt", "w");
  if (fout == NULL)
    printf("ошибка открытия текстового файла");
  
  fprintf(fout, "%s", arr);
  fclose(fout);
}

// fseek - перемещает файловый курсор
// ftell - возвращает текущую позицию в файле