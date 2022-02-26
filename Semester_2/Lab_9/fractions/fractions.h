struct fraction {
  long long koeff;
  long long divider;
};

void set_fraction(fraction *f, long long k, long long d);
long long get_gcd(long long a, long long b);
void simplify_fraction(fraction *f);
void print_fraction(fraction *f);
fraction* new_fraction(long long k, long long d);
void upd_fraction(fraction *f, long long k, long long d);