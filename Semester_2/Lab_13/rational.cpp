#include "rational.h"
#include <stdio.h>

Rational::Rational(double num, double denom) {
  // assert(denominator != 0);
  numerator = num;
  denominator = denom ? denom : 1;
}

void Rational::set(double num, double denom) {
  numerator = num;
  denominator = denom ? denom : 1; // защита от деления на ноль
}

double& Rational::get_numerator() { return numerator; }

double& Rational::get_denominator() { return denominator; }