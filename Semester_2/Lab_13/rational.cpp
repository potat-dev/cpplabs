#include "rational.h"
#include <stdio.h>
#include <assert.h>

using namespace std;

Rational::Rational(long long numerator, long long denominator) :
  _numerator(numerator),
  _denominator(denominator ? denominator : 1) {
  assert(denominator != 0);
}

Rational::Rational(const Rational &temp) :
  _numerator(temp._numerator),
  _denominator(temp._denominator) {
}

void Rational::set(long long numerator, long long denominator) {
  _numerator = numerator;
  _denominator = denominator ? denominator : 1;
}

long long& Rational::numerator() { return _numerator; }

long long& Rational::denominator() { return _denominator; }

double Rational::get_value() {return (double)_numerator / (double)_denominator; }

std::istream& operator>>(std::istream &in, Rational &r) {
  long long num, denom;
  in >> num; in >> denom;
  r.set(num, denom);
  return in;
}

std::ostream& operator<<(std::ostream &out, const Rational &r) {
  out << r._numerator << " / " << r._denominator;
  return out;
}
