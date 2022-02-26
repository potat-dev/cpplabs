#include <stdio.h>
#include <stdlib.h>

#include "fractions.h"

int main() { // ? test
  fraction *f = new_fraction();
  print_fraction(f);
  set_fraction(f, 6, 18);
  print_fraction(f);

  fraction *fr = new_fraction();
  print_fraction(fr);
  fraction *tt = new_fraction();
  // sum_fractions(tt, f, fr);

  sum_fractions(f, fr);

  print_fraction(f);

  // set_fraction(fr, 4342, 454);
  // simplify_fraction(fr);
  // print_fraction(fr);

  // set_fraction(fr, 39, 3);
  // simplify_fraction(fr);
  // print_fraction(fr);

  return 0;
}