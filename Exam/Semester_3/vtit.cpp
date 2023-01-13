#include <iostream>

using namespace std;

int main() {
  int a[4] = {1, 2, 3, 4};
  int cum_sum = 0;

  for (int i = 0; i < 4; i++) {
    cum_sum += a[i];
  }

  cout << cum_sum << endl;

  // divide by 4 via bit shift
  cum_sum = cum_sum >> 2;

  cout << cum_sum << endl;
  return 0;

  // pseudo code (assembly using add and sh)
  // add r0, r1
  // add r0, r2
  // add r0, r3
  // sh r0
  // sh r0
}