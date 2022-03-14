#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Rational {
  private:
    long long _numerator;   // числитель
    long long _denominator; // знаминатель
  
  public:
    Rational(long long numerator = 0, long long denominator = 1);
    Rational(const Rational &temp);
    
    void set(long long numerator, long long denominator);
    long long& numerator();
    long long& denominator();
    double get_value();

    friend std::istream& operator>>(std::istream &in, Rational &temp);
    friend std::ostream& operator<<(std::ostream &out, const Rational &temp);
};