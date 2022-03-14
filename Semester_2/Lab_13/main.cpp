// Создайте класс Rational (рациональная дробь) с операциями
// +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, *=, /, /=

// TODO:
//* приватные поля для данных
//* конструктор, содержащий значения по умолчанию
//* функции-элементы установки и извлечения значений
//* перегруженные операторы ввода и вывода
//? указанные в задании перегруженные операции
//? конструктор копий
//? оператор присваивания
//? деструктор

#include "rational.h"
using namespace std;

int main() {
  Rational test(1, 2);
  printf(
    "%d / %d = %f\n",
    (int)test.get_numerator(),
    (int)test.get_denominator(),
    test.get_value()
  );

  Rational test2(2, 3);
  test2.print();

  test2.get_denominator() = 42;
  printf("%f\n", test2.get_value());

  test2.get_numerator() = 42;
  printf("%f\n", test2.get_value());
  
  cout << test << ", " << test2 << endl;

  cin >> test;
  cout << "\n" << test << "\n";
}
