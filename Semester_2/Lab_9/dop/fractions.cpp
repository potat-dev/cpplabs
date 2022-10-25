#include "fractions.h"

#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b) {
  if (a == 0) return (b > 0) ? b : -b;
  return gcd(b % a, a);
}

void simplify_fraction(fraction *f) {
  long long factor = gcd(f->koeff, f->divider);
  f->koeff /= factor;
  f->divider /= factor;
}

fraction *new_fraction() {
  fraction *temp = (fraction *)malloc(sizeof(fraction));
  temp->koeff = 0;
  temp->divider = 1;
  return temp;
}

fraction *new_fraction(long long a) {
  fraction *temp = (fraction *)malloc(sizeof(fraction));
  temp->koeff = a;
  temp->divider = 1;
  return temp;
}

fraction *new_fraction(long long k, long long d) {
  fraction *temp = (fraction *)malloc(sizeof(fraction));
  temp->koeff = k;
  temp->divider = (d == 0) ? 1 : d;
  simplify_fraction(temp);
  return temp;
}

void set_fraction(fraction *f, long long k, long long d) {
  f->koeff = k;
  f->divider = (d == 0) ? 1 : d;
  simplify_fraction(f);
}

void set_fraction(fraction *f, long long k) {
  f->koeff = k;
  f->divider = 1;
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

void multiply_fractions(fraction *f, fraction *a, fraction *b) {
  f->koeff = a->koeff * b->koeff;
  f->divider = a->divider * b->divider;
  simplify_fraction(f);
}

void sum_multiply_fractions(fraction *f, fraction *a, fraction *b) {
  fraction temp;
  multiply_fractions(&temp, a, b);
  sum_fractions(f, &temp);
}

void print_fraction(fraction *f) {
  printf("%lld / %lld\n", f->koeff, f->divider);
}