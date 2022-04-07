#include <iostream>
using namespace std;

#define VERSION 2
// 0 - old version
// 1 - new version
// 2 - optimal solution

#if VERSION == 0

  #include "binom_koeff_v0.h"

  int main() {
    for (int i = 0; i <= 8; i++)
      cout << c(8, i) << endl;
  }

#elif VERSION == 1 

  #include "binom_koeff_v1.h"

  int main() {
    cout << "c(9,  7) = " << c(9,  7) << endl; // 36
    cout << "c(6,  3) = " << c(6,  3) << endl; // 20
    cout << "c(10, 5) = " << c(10, 5) << endl; // 252
    cout << "c(0,  7) = " << c(0,  7) << endl; // 0
    cout << "c(0,  0) = " << c(0,  0) << endl; // 0
    cout << "c(9,  1) = " << c(9,  1) << endl; // 9
    cout << "c(7,  6) = " << c(7,  6) << endl; // 7
    cout << "c(18, 6) = " << c(18, 6) << endl; // 18564
  }

#elif VERSION == 2

  #include "optimal_binom.h"

  int main() {
    uint64_t arr[5][3] = {
      {60, 30, 118264581564861424},
      {61,  8, 2944827765},
      {42, 21, 538257874440},
      {65, 32, 3609714217008132870},
      {99, 99, 1}
    }; 

    for (int i = 0; i < 5; i++)
      cout << c(arr[i][0], arr[i][1]) << " = " << arr[i][2] << endl;
  }

#else

  #error "incorrect version"

#endif