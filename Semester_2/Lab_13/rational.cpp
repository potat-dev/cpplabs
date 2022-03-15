#include "rational.h"
#include <assert.h>

using namespace std;

Rational::Rational(long long numerator, long long denominator) :
  _numerator(denominator > 0 ? numerator : -numerator),
  _denominator(denominator ? (denominator > 0 ? denominator : -denominator) : 1) {
  assert(denominator != 0);
}

Rational::Rational(const Rational &temp) :
  _numerator(temp._numerator),
  _denominator(temp._denominator) {
}

void Rational::set(long long numerator, long long denominator) {
  _numerator = denominator > 0 ? numerator : -numerator;
  _denominator = denominator ? (denominator > 0 ? denominator : -denominator) : 1;
}

long long& Rational::numerator() {
  return _numerator;
}

long long& Rational::denominator() {
  return _denominator;
}

double Rational::get_value() {
  return (double)_numerator / (double)_denominator;
}

istream& operator>>(istream &in, Rational &temp) {
  long long num, denom;
  in >> num; in >> denom;
  temp.set(num, denom);
  return in;
}

ostream& operator<<(ostream &out, const Rational &r) {
  out << r._numerator << " / " << r._denominator;
  return out;
}

Rational& Rational::operator=(const Rational &temp) {
  // Проверка на самоприсваивание
  if (this == &temp) return *this;
  // Выполняем копирование значений
  _numerator = temp._numerator;
  _denominator = temp._denominator;
  // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
  return *this;
} 

Rational& Rational::operator=(const long long &temp) {
  _numerator = temp;
  _denominator = 1;
  return *this;
}

bool operator==(const Rational &r1, const Rational &r2) {
  return (r1._numerator == r2._numerator &&
          r1._denominator == r2._denominator);
}

bool operator!= (const Rational &r1, const Rational &r2) {
  return !(r1 == r2);
}

const Rational Rational::operator+() {
  return Rational(_numerator, _denominator);
}

const Rational Rational::operator-() {
  return Rational(-_numerator, _denominator);
}

Rational& Rational::operator++() {
  _numerator += _denominator;
  return *this;
};

Rational& Rational::operator--() {
  _numerator -= _denominator;
  return *this;
};

Rational Rational::operator++(int) {
  // Создаем временный объект
  Rational temp(*this);
  // Используем оператор декремента версии префикс
  // для реализации перегрузки оператора декремента версии постфикс
  ++(*this);
  return temp; // Возвращаем временный объект
};

Rational Rational::operator--(int) {
  Rational temp(*this);
  --(*this);
  return temp;
};