#include "file.h"

using namespace std;

int file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
	int fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return fsize;
}

file *read_file(const char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL)
    perror("Error opening file");
  // read string from file
  int fsize = file_size(f);
  char *str = (char*) malloc(fsize * sizeof(char));
  for (int i = 0; i < fsize; i++) {
    str[i] = 0;
    str[i] = fgetc(f);
  }
  fclose(f);
  // create file structure
  file *temp_file = (file*) malloc(sizeof(file));
  temp_file -> str = str;
  temp_file -> size = fsize;
  return temp_file;
}