#include <stdio.h>
#include <math.h>

#define DEBUG

#define FREE 0
#define BAD  1
#define USED 2

typedef unsigned long long uint64;

#ifdef DEBUG
  void debug(uint64 *arr, int size) {
    printf("[ ");
    for (uint64 i = 0; i < size; i++)
      printf("%d ", arr[i]);
    printf("]\n");
  }
#endif

unsigned char count_ones(uint64 n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

bool has_free(uint64 *arr, int size) {
  for (uint64 i = 0; i < size; i++)
    if (arr[i] == FREE) return true;
  return false;
}

int main() {
  uint64 n = 5, d = 3;
  uint64 size = pow(2, n);
  uint64 next_free, count = 0;

  uint64 *marks = new uint64[size];
  uint64 *table = new uint64[size];
  for (uint64 i = 0; i < size; i++)
    marks[i] = table[i] = FREE;

  while (has_free(marks, size)) {
    for (next_free = 0; marks[next_free] != FREE; next_free++);
    table[count] = next_free;
    marks[table[count++]] = USED;

    for (uint64 i = 0; i < size; i++)
      if (marks[i] == FREE && count_ones(i ^ table[count - 1]) < d)
        marks[i] = BAD;

    #ifdef DEBUG
      debug(marks, size);
    #endif
  }

  printf("code table: ");
  for (uint64 i = 0; i < count; i++)
    printf("%d ", table[i]);
}