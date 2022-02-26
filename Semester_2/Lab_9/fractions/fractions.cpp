#include <stdio.h>
#include <stdlib.h>

struct fraction {
  long long koeff;
  long long divider;
};

void set_fraction(fraction *f, long long k, long long d) {
  f->koeff = k; f->divider = d;
}

long long get_gcd(long long a, long long b) {
  if (a == 0) return b;
  return get_gcd(b % a, a);
}

void simplify_fraction(fraction *f) {
  long long factor = get_gcd(f->koeff, f->divider);
  f->koeff /= factor; f->divider /= factor;
}

void print_fraction(fraction *f) {
  printf("%lld / %lld\n", f->koeff, f->divider);
}

fraction* new_fraction(long long k, long long d) {
  fraction *temp = (fraction *)malloc(sizeof(fraction));
  temp->koeff = k;
  temp->divider = d;
  simplify_fraction(temp);
  return temp;
}

void upd_fraction(fraction *f, long long k, long long d) {
  f->koeff = k;
  f->divider = d;
  simplify_fraction(f);
}