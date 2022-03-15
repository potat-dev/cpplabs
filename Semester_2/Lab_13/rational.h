#pragma once

#include <stdlib.h>
#include <iostream>

using namespace std;

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

    friend istream& operator>>(istream &in, Rational &temp);
    friend ostream& operator<<(ostream &out, const Rational &temp);

    Rational& operator=(const Rational &temp);
    Rational& operator=(const long long &temp);

    friend bool operator== (const Rational &r1, const Rational &r2);
    friend bool operator!= (const Rational &r1, const Rational &r2);

    // унарные операторы
    const Rational operator+();
    const Rational operator-();

    // префиксный инкремент
    Rational& operator++();
    Rational& operator--();
    
    // постфиксный инкремент
    Rational operator++(int);
    Rational operator--(int);
};