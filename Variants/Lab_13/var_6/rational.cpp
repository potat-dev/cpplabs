#include "rational.h"
#include <assert.h>

using namespace std;

long long gcd(long long a, long long b)
{
  if (a == 0)
    return (b > 0) ? b : -b;
  return gcd(b % a, a);
}

long long lcm(long long a, long long b)
{
  return (a * b) / gcd(a, b);
}

Rational::Rational(long long numerator, long long denominator) : _integer(0),
                                                                 _numerator(denominator > 0 ? numerator : -numerator),
                                                                 _denominator(denominator ? (denominator > 0 ? denominator : -denominator) : 1)
{
  assert(denominator != 0);
  this->simplify();
}

Rational::Rational(const Rational &temp, bool invert) : _integer(0),
                                                        _numerator(invert ? temp._denominator : temp._numerator),
                                                        _denominator(invert ? temp._numerator : temp._denominator)
{
  this->simplify();
}

Rational &Rational::set(long long numerator, long long denominator)
{
  _numerator = denominator > 0 ? numerator : -numerator;
  _denominator = denominator ? (denominator > 0 ? denominator : -denominator) : 1;
  return this->simplify();
}

long long &Rational::numerator()
{
  return _numerator;
}

long long &Rational::denominator()
{
  return _denominator;
}

long long &Rational::integer()
{
  return _integer;
}

double Rational::get_value()
{
  return (double)_numerator / (double)_denominator;
}

Rational &Rational::simplify()
{
  long long factor = gcd(_numerator, _denominator);
  if (_denominator < 0)
    factor *= -1;
  if (factor != 1)
  {
    _numerator /= factor;
    _denominator /= factor;
  }
  normalize();
  return *this;
}

Rational &Rational::normalize()
{
  if (!_integer)
    _integer = _numerator / _denominator;
  _numerator %= _denominator;
  // if (_integer && _numerator < 0) _numerator *= -1;
  return *this;
}

Rational &Rational::denormalize()
{
  // if (_integer < 0 && _numerator > 0) _numerator *= -1;
  _numerator += _integer * _denominator;
  _integer = 0;
  return *this;
}

istream &operator>>(istream &in, Rational &temp)
{
  long long num, denom;
  in >> num;
  in >> denom;
  temp.set(num, denom);
  return in;
}

ostream &operator<<(ostream &out, const Rational &r)
{
  long long num = r._numerator;
  if (r._integer)
  {
    out << r._integer;
    if (num)
    {
      if (r._integer > 0)
        out << "+";
      if (r._integer < 0)
        out << "-";
      if (num < 0)
        num *= -1;
    }
  }
  if (r._numerator)
  {
    out << "(" << num;
    if (r._denominator != 1)
      out << "/" << r._denominator;
    out << ")";
  }
  else
    out << 0;
  return out;
}

Rational &Rational::operator=(const Rational &temp)
{
  // if (this == &temp) return *this;
  // (бесполезно когда нет динамической памяти)
  _numerator = temp._numerator;
  _denominator = temp._denominator;
  return *this;
}

Rational &Rational::operator=(const long long &temp)
{
  _numerator = temp;
  _denominator = 1;
  return *this;
}

bool operator==(const Rational &r1, const Rational &r2)
{
  return (r1._integer == r2._integer &&
          r1._numerator == r2._numerator &&
          r1._denominator == r2._denominator);
}

bool operator!=(const Rational &r1, const Rational &r2)
{
  return !(r1 == r2);
}

const Rational Rational::operator+()
{
  return Rational(_numerator + _integer * _denominator, _denominator);
}

const Rational Rational::operator-()
{
  return Rational(-(_numerator + _integer * _denominator), _denominator);
}

Rational &Rational::operator++()
{
  _numerator += _denominator;
  return *this;
};

Rational &Rational::operator--()
{
  _numerator -= _denominator;
  return *this;
};

Rational Rational::operator++(int)
{
  Rational temp(*this);
  ++(*this);
  return temp;
};

Rational Rational::operator--(int)
{
  Rational temp(*this);
  --(*this);
  return temp;
};

// + - * /

Rational operator+(const Rational &r1, const Rational &r2)
{
  Rational temp(
      (r1._numerator + r1._integer * r1._denominator) * r2._denominator +
          (r2._numerator + r2._integer * r2._denominator) * r1._denominator,
      r1._denominator * r2._denominator);
  return temp.simplify();
};

Rational operator+(const Rational &r, long long value)
{
  Rational temp(value);
  return temp + r;
};

Rational operator+(long long value, const Rational &r)
{
  return r + value;
};

Rational operator-(const Rational &r1, const Rational &r2)
{
  Rational temp(-r2._numerator, r2._denominator);
  return r1 + temp;
};

Rational operator-(const Rational &r, long long value)
{
  Rational temp(value);
  return r - temp;
};

Rational operator-(long long value, const Rational &r)
{
  Rational temp(value);
  return temp - r;
};

Rational operator*(const Rational &r1, const Rational &r2)
{
  Rational temp(
      (r1._numerator + r1._integer * r2._denominator) * (r2._numerator + r2._integer + r2._denominator),
      r1._denominator * r2._denominator);
  return temp.simplify();
};

Rational operator*(const Rational &r, long long value)
{
  Rational temp(value);
  return r * temp;
};

Rational operator*(long long value, const Rational &r)
{
  return r * value;
};

Rational operator/(const Rational &r1, const Rational &r2)
{
  Rational temp(r2, INVERSE); // обратная дробь
  return r1 * temp;
};

Rational operator/(const Rational &r, long long value)
{
  Rational temp(value);
  return r / temp;
};

Rational operator/(long long value, const Rational &r)
{
  Rational temp(value);
  return temp / r;
};

// += -= *= /=

Rational &operator+=(Rational &left, const Rational &right)
{
  left = left + right;
  return left;
};

Rational &operator+=(Rational &left, const long long &right)
{
  left = left + right;
  return left;
};

Rational &operator-=(Rational &left, const Rational &right)
{
  left = left - right;
  return left;
};

Rational &operator-=(Rational &left, const long long &right)
{
  left = left - right;
  return left;
};

Rational &operator*=(Rational &left, const Rational &right)
{
  left = left * right;
  return left;
};

Rational &operator*=(Rational &left, const long long &right)
{
  left = left * right;
  return left;
};

Rational &operator/=(Rational &left, const Rational &right)
{
  left = left / right;
  return left;
};

Rational &operator/=(Rational &left, const long long &right)
{
  left = left / right;
  return left;
};

// < <= > >=

bool operator>(const Rational &r1, const Rational &r2)
{
  long long L = lcm(r1._denominator, r2._denominator);
  return (
      (r1._numerator + r1._integer * r1._denominator) * L / r1._denominator >
      (r2._numerator + r1._integer * r1._denominator) * L / r2._denominator);
};

bool operator<=(const Rational &r1, const Rational &r2)
{
  return (r1 == r2 || r1 < r2);
};

bool operator<(const Rational &r1, const Rational &r2)
{
  return r2 > r1;
};

bool operator>=(const Rational &r1, const Rational &r2)
{
  return (r1 == r2 || r1 > r2);
};

// сортировка Шелла

void ShellSort(int n, Rational *mass[])
{
  int i, j, step;
  Rational *tmp;
  for (step = n / 2; step > 0; step /= 2)
    for (i = step; i < n; i++)
    {
      tmp = mass[i];
      for (j = i; j >= step; j -= step)
      {
        if (*tmp < *mass[j - step])
          mass[j] = mass[j - step];
        else
          break;
      }
      mass[j] = tmp;
    }
}