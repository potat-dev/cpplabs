#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Rational {
  private:
    double numerator;   // числитель
    double denominator; // знаминатель
  
  public:
    Rational(double num = 0, double denom = 1);
    void set(double num, double denom);
    double& get_numerator();
    double& get_denominator();
    double get_value();
    void print();

    friend std::istream& operator>>(std::istream &in, Rational &r);
    friend std::ostream& operator<<(std::ostream &out, const Rational &r);
};