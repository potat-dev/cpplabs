#include <stdio.h>
#include <stdlib.h>

void main() {
  int n = 0;
  scanf("%d\n", &n);

  char* arr = (char*) malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++)
    scanf("%c", &arr[i]);
  arr[n] = 0;

  printf("%s\n", arr);

  arr = (char*) realloc(arr, (2*n+1) * sizeof(char));
  for (int i = 0; i < n; i++)
    arr[i+n] = arr[i];
  arr[2*n] = 0;

  printf("%s", arr);

  free(arr);
}