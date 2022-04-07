#include <iostream>
#include "v_small_array.h"

using namespace std;

#define MODE 2
// 0 - default test
// 1 - speed test
// 2 - statistics

#if MODE == 0

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

#elif MODE == 1

  #include <chrono>
  #define ITERS 32

  int main () {
    unsigned long long iters = 1;

    for (int i = 1; i < ITERS; i++) {
      iters *= 2;
      unsigned int temp = 0;
      auto begin = chrono::steady_clock::now();

      for (unsigned long i = 0; i < iters; i++)
        temp = count_ones(i);

      auto end = chrono::steady_clock::now();
      auto time = chrono::duration_cast<chrono::milliseconds>(end - begin);

      cout << "Elapsed time for (" << iters << " iterations): "
           << time.count() << " ms, ["
           << (double)time.count() / (double)iters << " ms/iter]" << endl;
    }
  }

#elif MODE == 2

  int main() {
    int n;
    cin >> n;
    int stats[n + 1] = {0};

    unsigned long long power = 1;
    for (int i = 0; i < n; i++)
      power *= 2;

    for (unsigned long long i = 0; i < power; i++)
      stats[count_ones(i)]++;

    for (int i = 0; i <= n; i++)
      cout << "with " << i << " ones: " << stats[i] << endl;
  }

#else

  #pragma message "Incorrect configuration"

#endif