// Создайте класс Rational (рациональная дробь)

// TODO:
//* приватные поля для данных
//* конструктор, содержащий значения по умолчанию
//* функции-элементы установки и извлечения значений
//* перегруженные операторы ввода и вывода
//* конструктор копий
//* оператор присваивания
//? указанные в задании перегруженные операции
// +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, *=, /, /=

#include "rational.h"
using namespace std;

int main() {
  Rational r;
  cout << r << endl;

  Rational test(1, 2);
  Rational test2(2, 3);

  // конструктор копии
  Rational test3(test);

  cout << test.numerator() << " / "
       << test.denominator() << " = "
       << test.get_value() << endl;

  cout << test << " = " << test.get_value() << endl;

  test2.denominator() = 42;
  cout << test2.get_value() << endl;

  test2.numerator() = 42;
  cout << test2.get_value() << endl;
  
  cout << test << ", "
       << test2 << endl;

  cout << "\nenter rational: ";
  cin >> test;
  cout << test << " = " << test.get_value() << "\n\n";

  cout << test3 << " = " << test3.get_value() << "\n\n";

  Rational r1(1, 2);
  Rational r2(1, 3);
  Rational r3(1, 4);

  r1 = r2 = r3; // = 1 / 4
  cout << r1 << ", "
       << r2 << ", "
       << r3 << endl;

  r1 = r2 = r3 = 42;
  cout << r1 << ", "
       << r2 << ", "
       << r3 << endl;
}
