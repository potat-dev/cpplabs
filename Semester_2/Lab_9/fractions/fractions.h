#pragma once

struct fraction {
  long long koeff;
  long long divider;
};

void set_fraction(fraction *f, long long k, long long d);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
void simplify_fraction(fraction *f);
void print_fraction(fraction *f);
void upd_fraction(fraction *f, long long k, long long d);
void sum_fractions(fraction *a, fraction *b, fraction *c);
void sum_fractions(fraction *a, fraction *b);
fraction* new_fraction(long long k, long long d);
fraction* new_fraction();