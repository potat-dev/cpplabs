#include <stdio.h>
#include <stdlib.h>

#include "polynom.h"

int main(int argc, char const *argv[])
{
  int arr[4] = {0};
  polynom *test = new_polynom(arr, 4);

  for (int a = 0; a < 3; a++)
  for (int b = 0; b < 3; b++)
  for (int c = 0; c < 3; c++)
  for (int d = 0; d < 3; d++) {
    arr[0] = d; arr[1] = c;
    arr[2] = b; arr[3] = a;
    upd_polynom(test, arr, 4);
    printf("%d %d %d %d : ", a, b, c, d);
    print_polynom(test);
  }
}