#pragma once

struct fraction {
  long long koeff;
  long long divider;
};

fraction* new_fraction(long long k, long long d); // {k, d}
fraction* new_fraction(long long k); // {a, 1}
fraction* new_fraction(); // {0, 1}

long long gcd(long long a, long long b);
void simplify_fraction(fraction *f);

void set_fraction(fraction *f, long long k, long long d); // {k, d}
void set_fraction(fraction *f, long long k); // {k, 1}
void print_fraction(fraction *f); 

void sum_fractions(fraction *a, fraction *b); // a += b
void sum_fractions(fraction *x, fraction *a, fraction *b); // x = a + b
void multiply_fractions(fraction *f, fraction *a, fraction *b); // f = a * b
void sum_multiply_fractions(fraction *f, fraction *a, fraction *b); // f += a * b