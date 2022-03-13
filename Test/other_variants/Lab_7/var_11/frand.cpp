#include "frand.h"

float normal_frand_n(int count, int n) {
  float sum = 0;
  for (int i = 0; i < count; i++)
    sum += frand_n(n);
  return sum / count;
}

void pretty_print(int *arr, int N, int wide) {
  int max = 0;
  for (int i = 0; i < N * 2; i++)
    if (arr[i] > max) max = arr[i];
  int w = max / wide;
  
  for (int i = 0; i < N * 2; i++) {
    printf("(%2d, %2d)  %6d | ", i-N, i-N+1, arr[i]);
    for (int j = 0; j < arr[i] / w; j++) printf("#");
    printf("\n");
  } 
}