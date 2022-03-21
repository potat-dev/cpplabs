#define VERSION 3
// 0 - old version
// 1 - new version
// 2 - optimal solution

#include <iostream>
using namespace std;

#if VERSION == 0

  #include "old_combinations.h"

  int main() {
    for (int i = 0; i <= 8; i++)
      cout << c(8, i) << endl;
  }

#elif VERSION == 1 

  #include "binom_koeff.h"

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
    // тут пока пусто
  }

#else

  #pragma message "incorrect version"

  int main() {}

#endif