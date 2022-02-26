#include <stdio.h>
#include <stdlib.h>

#include "fractions.h"

int main() {
  fraction f;
  upd_fraction(&f, 6, 18);
  print_fraction(&f);

  fraction *fr = new_fraction(13, 26);
  // set_fraction(fr, 2, 3);
  // simplify_fraction(fr);
  print_fraction(fr);

  set_fraction(fr, 4342, 454);
  simplify_fraction(fr);
  print_fraction(fr);

  set_fraction(fr, 39, 3);
  simplify_fraction(fr);
  print_fraction(fr);

  return 0;
}