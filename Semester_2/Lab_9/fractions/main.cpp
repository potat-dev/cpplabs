#include <stdio.h>
#include <stdlib.h>

#include "fractions.h"

int main() { // ? test
  fraction *f = new_fraction();
  fraction *f1 = new_fraction();
  fraction *f2 = new_fraction();

  print_fraction(f1);
  set_fraction(f1, 6, 18);
  print_fraction(f1);
  print_fraction(f2);
  set_fraction(f2, 42343342, 425236560);
  sum_fractions(f1, f2);
  print_fraction(f1); //* correct!

  set_fraction(f, 423, 1618);
  set_fraction(f1, 42, 4);
  set_fraction(f2, 2343, 67);
  sum_multiply_fractions(f, f1, f2);
  print_fraction(f); //* correct!

  set_fraction(f1, 0, 1);
  set_fraction(f2, 618, 1);
  multiply_fractions(f, f1, f2);
  print_fraction(f); //* correct!
}