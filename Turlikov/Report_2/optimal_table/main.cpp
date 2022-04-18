#include <iostream>
#include "stdio.h"

#define FREE 0
#define BAD  1
#define USED 2

using namespace std;

unsigned int pow2(int p) {
  unsigned int temp = 1;
  while (p-- > 0) temp *= 2;
  return temp;
}

unsigned char count_ones(unsigned char n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

void debug(unsigned char *arr1, unsigned char *arr2, int size) {
  cout << "A   : ";
  for (int i = 0; i < size; i++)
    printf("%d, ", arr1[i]);
    // cout << '0' + arr1[i] << ", ";
  cout << endl;
  cout << "mark: ";
  for (int i = 0; i < size; i++)
    printf("%d, ", arr2[i]);
    // cout << '0' + arr2[i] << ", ";
  cout << endl;
}

bool has_free(unsigned char *arr, int size) {
  for (int i = 0; i < size; i++)
    if (arr[i] == FREE) return true;
  return false;
}

int main() {
  unsigned int n, d, size, count = 0;
  cout << "Enter n, d: ";
  cin >> n; cin >> d;

  size = pow2(n);
  unsigned char mark[size] = { FREE };
  unsigned char A[size] = { FREE };

  // A[0] = 0;
  // mark[0] = USED;
  // count++;

  while (has_free(mark, size)) {
    // A[0] = 0;
    // mark[0] = USED;
    // count++;

    // шаг 1
    for (int i = 0; i < size; i++)
      if (mark[i] == FREE) {
        A[count++] = i;
        mark[i] = USED;
      }

    // шаг 2
    for (int i = 0; i < size; i++)
      if (mark[i] == FREE && count_ones(i ^ A[count - 1]) < d)
        mark[i] = BAD;

    cout << "iter: " << count << endl;
    debug(A, mark, size);
    cout << endl;
  }
}