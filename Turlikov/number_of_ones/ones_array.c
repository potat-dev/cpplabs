#include <stdio.h>
#include "var_1.c"

#define L 9 
void main() {
  int arr[L + 1] = {0};
  for (unsigned long long i = 0; i < ((unsigned long long)1) << L ; i++) {
    arr[count_ones(i)]++;
  }
  for (int i = 0; i <= L; i++)
    printf("%d - %d\n", i, arr[i]);
}