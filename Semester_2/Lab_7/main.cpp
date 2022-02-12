#include <stdio.h>
#include "rand.h"

#define ITERS 100000
#define NUMS  211

int main () {
  int array[NUMS] = {0};
   for (int i = 0; i < ITERS; i++)
     array[gen()]++;

  printf("%-4s| %s\n----|-----\n", "num", "freq");
  for (int i = 0; i < NUMS; i++)
    printf("%-4d| %d\n", i, array[i]);
}