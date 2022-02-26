#include <stdio.h>
#include <stdlib.h>

#include "fractions.h"

long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

void simplify_fraction(fraction *f) {
  long long factor = gcd(f->koeff, f->divider);
  f->koeff /= factor; f->divider /= factor;
}

void set_fraction(fraction *f, long long k, long long d) {
  f->koeff = k; f->divider = (d == 0) ? 1 : d;
  simplify_fraction(f);
}

void sum_fractions(fraction *x, fraction *a, fraction *b) {
  x->divider = a->divider * b->divider;
  x->koeff = a->koeff * b->divider + b->koeff * a->divider;
  simplify_fraction(x);
}

void sum_fractions(fraction *a, fraction *b) {
  long long ak = a->koeff, ad = a->divider;
  a->divider = ad * b->divider;
  a->koeff = ak * b->divider + b->koeff * ad;
  simplify_fraction(a);
}

void print_fraction(fraction *f) {
  printf("%lld / %lld\n", f->koeff, f->divider);
}

fraction* new_fraction() {
  fraction *temp = (fraction *)malloc(sizeof(fraction));
  temp->koeff = temp->divider = 1;
  return temp;
}

fraction* new_fraction(long long k, long long d) {
  fraction *temp = (fraction *)malloc(sizeof(fraction));
  temp->koeff = k;
  temp->divider = (d == 0) ? 1 : d;
  simplify_fraction(temp);
  return temp;
}