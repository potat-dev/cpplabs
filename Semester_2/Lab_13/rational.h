#pragma once

#include <stdio.h>
#include <stdlib.h>

class Rational {
  private:
    double numerator;   // числитель
    double denominator; // знаминатель
  
  public:
    Rational(double num = 0, double denom = 1);
    void set(double num, double denom);
    double& get_numerator();
    double& get_denominator();
};