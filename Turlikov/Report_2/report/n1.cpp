#include <iostream>
using namespace std;
typedef unsigned long long uint64;

static uint64 A[] = {0x00, 0x0d, 0x16, 0x1f};

uint64 coder   (uint64 m)           { return A[m]; }
uint64 channel (uint64 a, uint64 e) { return a ^ e; }
uint64 hamming (uint64 a, uint64 b) { return count_ones(a ^ b); }

uint64 count_ones(uint64 n) {
  uint64 w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

uint64 decoder(uint64 m) {
  uint64 ind = 0, min = 5;
  for (uint64 i = 0; i < 4; i++) {
    uint64 d = hamming(m, A[i]);
    if (d < min) {
      min = d; ind = i;
    }
  }
  return ind;
}

int main() {
  uint64 m, e, w, c, d;
  cin >> m >> e;
  w = coder(m); c = channel(w, e); d = decoder(c);
  cout << "m: " << m << endl;
  cout << "w: " << w << endl;
  cout << "e: " << e << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
}





