#pragma once

#include <stdlib.h>
#include <iostream>

using namespace std;

#define INVERSE true

class Rational {
  private:
    long long _numerator;   // числитель
    long long _denominator; // знаминатель
  
  public:
    Rational(long long numerator = 0, long long denominator = 1);
    Rational(const Rational &temp, bool invert = false);

    Rational& set(long long numerator, long long denominator);
    long long& numerator();
    long long& denominator();

    double get_value();
    Rational& simplify();

    friend istream& operator>>(istream &in, Rational &temp);
    friend ostream& operator<<(ostream &out, const Rational &temp);

    Rational& operator=(const Rational &temp);
    Rational& operator=(const long long &temp);

    friend bool operator==(const Rational &r1, const Rational &r2);
    friend bool operator!=(const Rational &r1, const Rational &r2);

    // унарные операторы
    const Rational operator+() = delete; // унарный плюс бесполезен
    const Rational operator-();

    // префиксный инкремент
    Rational& operator++();
    Rational& operator--();
    
    // постфиксный инкремент
    Rational operator++(int);
    Rational operator--(int);

    friend Rational operator+(const Rational &r1, const Rational &r2);
	  friend Rational operator+(const Rational &r, long long value);
	  friend Rational operator+(long long value, const Rational &r);

    friend Rational operator-(const Rational &r1, const Rational &r2);
	  friend Rational operator-(const Rational &r, long long value);
	  friend Rational operator-(long long value, const Rational &r);
    
    friend Rational operator*(const Rational &r1, const Rational &r2);
	  friend Rational operator*(const Rational &r, long long value);
	  friend Rational operator*(long long value, const Rational &r);

    friend Rational operator/(const Rational &r1, const Rational &r2);
	  friend Rational operator/(const Rational &r, long long value);
	  friend Rational operator/(long long value, const Rational &r);

    friend Rational& operator+=(Rational& left, const Rational& right);
    friend Rational& operator+=(Rational& left, const long long& right);
    
    friend Rational& operator-=(Rational& left, const Rational& right);
    friend Rational& operator-=(Rational& left, const long long& right);
    
    friend Rational& operator*=(Rational& left, const Rational& right);
    friend Rational& operator*=(Rational& left, const long long& right);
    
    friend Rational& operator/=(Rational& left, const Rational& right);
    friend Rational& operator/=(Rational& left, const long long& right);

    friend bool operator>(const Rational&r1, const Rational &r2);
    friend bool operator<=(const Rational &r1, const Rational &r2);
 
    friend bool operator<(const Rational &r1, const Rational &r2);
    friend bool operator>=(const Rational &r1, const Rational &r2);
};