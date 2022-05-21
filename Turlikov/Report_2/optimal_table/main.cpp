#include <stdio.h>
#include <math.h>

#define DEBUG

#define FREE 0
#define BAD  1
#define USED 2

unsigned char count_ones(unsigned char n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

#ifdef DEBUG
  void debug(unsigned char *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++)
      printf("%d ", arr[i]);
    printf("]\n");
  }
#endif

bool has_free(unsigned char *arr, int size) {
  for (int i = 0; i < size; i++)
    if (arr[i] == FREE) return true;
  return false;
}

int main() {
  unsigned int n = 5, d = 3;
  unsigned int size = pow(2, n);
  unsigned int next_free, count = 0;

  unsigned char mark[size] = { FREE };
  unsigned char table[size] = { FREE };

  while (has_free(mark, size)) {
    for (next_free = 0; mark[next_free] != FREE; next_free++);
    table[count] = next_free;
    mark[table[count++]] = USED;

    for (unsigned int i = 0; i < size; i++)
      if (mark[i] == FREE && count_ones(i ^ table[count - 1]) < d)
        mark[i] = BAD;

    #ifdef DEBUG
      debug(mark, size);
    #endif
  }

  printf("code table: ");
  for (int i = 0; i < count; i++)
    printf("%d ", table[i]);
}