#include "rational.h"
#include <stdio.h>

Rational::Rational(double num, double denom) {
  numerator = num;
  denominator = denom ? denom : 1;
}

void Rational::set(double num, double denom) {
  numerator = num;
  denominator = denom ? denom : 1;
}

double& Rational::get_numerator() { return numerator; }

double& Rational::get_denominator() { return denominator; }

double Rational::get_value() {return numerator / denominator; }

void Rational::print() { printf("%d / %d\n", (int)numerator, (int)denominator); }


std::istream& operator>>(std::istream &in, Rational &r) {
  double num, denom;
  in >> num; in >> denom;
  r.set(num, denom);
  return in;
}

std::ostream& operator<<(std::ostream &out, const Rational &r) {
  out << r.numerator << " / " << r.denominator;
  return out;
}
