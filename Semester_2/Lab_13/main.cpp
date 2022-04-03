// Создайте класс Rational (рациональная дробь)

// TODO:
//* приватные поля для данных
//* конструктор, содержащий значения по умолчанию
//* функции-элементы установки и извлечения значений
//* перегруженные операторы ввода и вывода
//* конструктор копий
//* оператор присваивания

//? указанные в задании перегруженные операции
//* выполнено ++, --, +r, -r, ==, !=, =, +, +=, -, -=, *, *=, /, /=
//! не готово >, <, >=, <=

#include "rational.h"
using namespace std;

// тестирование функций класса
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
  
  cout << test << ", " << test2 << endl;

  cout << endl << "Enter rational: ";
  cin >> test;
  cout << test << " = " << test.get_value() << "\n\n";
  cout << test3 << " = " << test3.get_value() << "\n\n";

  Rational r1(1, 2);
  Rational r2(1, 3);
  Rational r3(1, 4);

  r1 = r2 = r3; // = 1 / 4
  cout << r1 << ", " << r2 << ", " << r3 << endl;

  r1 = r2 = r3 = 42;
  cout << r1 << ", " << r2 << ", " << r3 << endl;

  cout << test << ", " << -test << ", " << ++test;

  Rational testA(1, 2);
  Rational testB(1, 2);

  cout << endl;
  if (testA == testB) cout << "testA == testB" << endl;
  if (testA == testA) cout << "testA == testA" << endl;

  Rational testNew(testA);
  if (testA == testNew) cout << "testA == testNew" << endl;

  cout << ++testNew << ", " << testNew << endl;
  if (testA == testNew) cout << "testA == testNew" << endl;
  
  cout << testA++ << ", " << testA << endl;
  if (testA == testNew) cout << "testA == testNew" << endl;

  Rational temp(10, -20);
  cout << temp << ", " << temp.simplify() << ", " << temp << endl;


  cout << "\n/-- tests 1 --/\n\n";

  Rational kek_1(42, 618);
  Rational kek_2(69, 420);
  long long kek_n = 777;

  cout << "(" << kek_1 << ") + (" << kek_2 << ") = " << kek_1 + kek_2 << endl;
  cout << "(" << kek_1 << ") + (" << kek_n << ") = " << kek_1 + kek_n << endl;
  cout << "(" << kek_n << ") + (" << kek_1 << ") = " << kek_n + kek_1 << endl;
  
  cout << "(" << kek_1 << ") - (" << kek_2 << ") = " << kek_1 - kek_2 << endl;
  cout << "(" << kek_1 << ") - (" << kek_n << ") = " << kek_1 - kek_n << endl;
  cout << "(" << kek_n << ") - (" << kek_1 << ") = " << kek_n - kek_1 << endl;
  
  cout << "(" << kek_1 << ") * (" << kek_2 << ") = " << kek_1 * kek_2 << endl;
  cout << "(" << kek_1 << ") * (" << kek_n << ") = " << kek_1 * kek_n << endl;
  cout << "(" << kek_n << ") * (" << kek_1 << ") = " << kek_n * kek_1 << endl;
  
  cout << "(" << kek_1 << ") / (" << kek_2 << ") = " << kek_1 / kek_2 << endl;
  cout << "(" << kek_1 << ") / (" << kek_n << ") = " << kek_1 / kek_n << endl;
  cout << "(" << kek_n << ") / (" << kek_1 << ") = " << kek_n / kek_1 << endl;

  cout << "\n/-- tests 2 --/\n\n";

  kek_1 = {42, 618}; kek_2 = {69, 420}; kek_n = 777;
  cout << "(" << kek_1 << ") += (" << kek_2 << ") -> " << (kek_1 += kek_2) << endl;
  cout << "(" << kek_1 << ") += (" << kek_n << ") -> " << (kek_1 += kek_n) << endl;

  kek_1 = {42, 618}; kek_2 = {69, 420}; kek_n = 777;
  cout << "(" << kek_1 << ") -= (" << kek_2 << ") -> " << (kek_1 -= kek_2) << endl;
  cout << "(" << kek_1 << ") -= (" << kek_n << ") -> " << (kek_1 -= kek_n) << endl;

  kek_1 = {42, 618}; kek_2 = {69, 420}; kek_n = 777;
  cout << "(" << kek_1 << ") *= (" << kek_2 << ") -> " << (kek_1 *= kek_2) << endl;
  cout << "(" << kek_1 << ") *= (" << kek_n << ") -> " << (kek_1 *= kek_n) << endl;

  kek_1 = {42, 618}; kek_2 = {69, 420}; kek_n = 777;
  cout << "(" << kek_1 << ") /= (" << kek_2 << ") -> " << (kek_1 /= kek_2) << endl;
  cout << "(" << kek_1 << ") /= (" << kek_n << ") -> " << (kek_1 /= kek_n) << endl;
}

void test() {
  Rational r;
  for (int i = 1; i < 30; i++) {
    Rational temp(1, i);
    r = r + temp;
    cout << r << " = " << r.get_value() << endl;
  }
}