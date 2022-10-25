#include <iostream>
using namespace std;

static unsigned long long A[] = {0x00, 0x0d, 0x16, 0x1f};

unsigned long long count_ones(unsigned long long n) {
  unsigned long long w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

int min_hamming(unsigned long long* arr, int size) {
  int minim = size;
  for (unsigned long long a = 0; a < size; a++) {
    for (unsigned long long b = a + 1; b < size; b++) {
      if (arr[a] != arr[b]) {
        int hamm = count_ones(arr[a] ^ arr[b]);
        minim = hamm < minim ? hamm : minim;
      }
    }
  }
  return minim;
}

int main() {
  cout << "min hamming distance: %d\n" << min_hamming(A, 4);
}



