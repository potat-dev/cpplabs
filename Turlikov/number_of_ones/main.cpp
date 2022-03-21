#include <iostream>
using namespace std;

#include "v_small_array.h"

int main () {
  unsigned int n_32 = 0;
  unsigned long long n_64 = 0;
  cout << "zero 32: " << count_ones(n_32) << endl;
  cout << "zero 64: " << count_ones(n_64) << endl;
  
  n_32 = 0xffffffff;         // 4294967295 (2^32)
  n_64 = 0xffffffffffffffff; // 1844674407370955161 (2^64)
  cout << "test 32: " << count_ones(n_32) << endl;
  cout << "test 64: " << count_ones(n_64) << endl;

  n_32 = 42424242;
  n_64 = 4242424242424242;
  cout << "rand 32: " << count_ones(n_32) << endl;
  cout << "rand 64: " << count_ones(n_64) << endl;
}