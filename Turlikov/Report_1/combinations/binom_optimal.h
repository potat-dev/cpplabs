#include <stdint.h>
// #include <iostream>
using namespace std;

uint64_t c (uint16_t n, uint16_t k) {
  if (n == 0 || n < k) return 0;
  if (k == 0 || n == k) return 1;
  if (k == 1 || k == n - 1) return n;

  uint16_t len = (n - k > k ? k : n - k); // min (k, n - k)
  
  double answer = 1;
  for (uint16_t i = 0; i < len; i++)
    answer *= ((double)(n - i) / (double)(i + 1));

    // cout << (n - i) << " / "
    //      << (i + 1) << " = "
    //      << ((double)(n - i) / (double)(i + 1))
    //      << endl;

  return (uint64_t) answer;
}