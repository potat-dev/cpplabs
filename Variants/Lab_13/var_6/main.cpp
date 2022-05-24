// Создайте класс Rational (рациональная дробь)

// TODO:
// приватные поля для данных
// конструктор, содержащий значения по умолчанию
// функции-элементы установки и извлечения значений
// перегруженные операторы ввода и вывода
// конструктор копий
// оператор присваивания
// указанные в задании перегруженные операции
// ++ -- -n == != = + += - -= * *= / /= > < >= <=

// Исправить:
//* - поправить вывод
//* - !!!учесть отрицательные числа

// Доп:
//* - добавить целую часть (в сам класс)
//* - операции, соотв., с учетом целой части дробей
//* - сортировка Шелла массива дробей

#include "rational.h"
using namespace std;

// тестирование функций класса
int main() {
  int test_n = 0;
  cout << "Run test #";
  cin >> test_n;

  switch (test_n) {
    case 0: {
      Rational r1(-11205729, 14420), r2(3349, 14420), r3(11207689, 14420), r4(5439, 103);
      cout << r1 << " = " << r1.normalize() << " = " << r1.normalize() << " = " << r1.denormalize() << endl;
      cout << r2 << " = " << r2.normalize() << " = " << r2.normalize() << " = " << r2.denormalize() << endl;
      cout << r3 << " = " << r3.normalize() << " = " << r3.normalize() << " = " << r3.denormalize() << endl;
      cout << r4 << " = " << r4.normalize() << " = " << r4.normalize() << " = " << r4.denormalize() << endl;
      break;
    }
    
    case 1: {
      // тут тестируются:
      // конструкторы, геттеры, сеттеры,
      // вывод, конструктор копий, присваивания

      Rational lol(1, 2), kek = {2, 3};
      cout << "Rational 1 / 2: " << lol << endl;
      cout << "Rational 2 / 3: " << kek << endl;

      Rational temp(618);
      cout << "Int 618 to Rational: " << temp << endl;

      Rational test(42, 618);
      cout << "42 / 618 = " << test << " -> ";

      test.set(618, 42);
      cout << test << " -> ";
      cout << test.numerator() << " / "
           << test.denominator() << " -> ";

      test.numerator() = 6;
      test.denominator() = 18;
      cout << test << endl;

      Rational test_copy(test);
      cout << test << " = " << test.simplify()
           << " => copy: " << test_copy << endl;

      lol = kek = temp = test;
      cout << lol << ", "
           << kek << ", "
           << temp << endl;
      break;
    }

    case 2: {
      // тут тестируются:
      // ++ -- -n + += - -= * *= / /=

      Rational lol(42, 618);
      Rational kek(69, 420);
      long long abc = 777;

      cout << "++" << lol << " = " << ++lol << "\n";
      cout << "--" << lol << " = " << --lol << "\n";
      cout << "-" << lol << " = " << -lol << "\n";

      cout << lol << " + " << kek << " = " << lol + kek << endl;
      cout << lol << " + " << abc << " = " << lol + abc << endl;
      cout << abc << " + " << lol << " = " << abc + lol << endl;

      cout << lol << " - " << kek << " = " << lol - kek << endl;
      cout << lol << " - " << abc << " = " << lol - abc << endl;
      cout << abc << " - " << lol << " = " << abc - lol << endl;

      cout << lol << " * " << kek << " = " << (lol * kek).normalize() << endl;
      cout << lol << " * " << abc << " = " << (lol * abc).normalize() << endl;
      cout << abc << " * " << lol << " = " << (abc * lol).normalize() << endl;

      cout << lol << " / " << kek << " = " << lol / kek << endl;
      cout << lol << " / " << abc << " = " << lol / abc << endl;
      cout << abc << " / " << lol << " = " << abc / lol << endl;

      lol = {42, 618};
      kek = {69, 420};
      abc = 777;
      cout << lol << " += " << kek << " -> " << (lol += kek) << endl;
      cout << lol << " += " << abc << " -> " << (lol += abc) << endl;

      lol = {42, 618};
      kek = {69, 420};
      abc = 777;
      cout << lol << " -= " << kek << " -> " << (lol -= kek) << endl;
      cout << lol << " -= " << abc << " -> " << (lol -= abc) << endl;

      lol = {42, 618};
      kek = {69, 420};
      abc = 777;
      cout << lol << " *= " << kek << " -> " << (lol *= kek) << endl;
      cout << lol << " *= " << abc << " -> " << (lol *= abc) << endl;

      lol = {42, 618};
      kek = {69, 420};
      abc = 777;
      cout << lol << " /= " << kek << " -> " << (lol /= kek) << endl;
      cout << lol << " /= " << abc << " -> " << (lol /= abc) << endl;

      break;
    }

    case 3: {
      // тут тестируются:
      // == != > >= < <=

      Rational testA(1, 2);
      Rational testB(1, 2);

      if (testA == testB)
        cout << "testA == testB" << endl;
      if (testA == testA)
        cout << "testA == testA" << endl;

      Rational testNew(testA);
      if (testA == testNew)
        cout << "testA == testNew" << endl;

      cout << ++testNew << ", " << testNew << endl;
      if (testA == testNew)
        cout << "testA == testNew" << endl;

      cout << testA++ << ", " << testA << endl;
      if (testA == testNew)
        cout << "testA == testNew" << endl;

      Rational temp(10, -20);
      cout << temp << ", " << temp.simplify() << ", " << temp << endl;

      Rational lol = {42, 618}, kek = {69, 420};
      cout << lol << " > " << kek << (lol > kek ? " = True" : " = False") << endl;
      cout << lol << " >= " << kek << (lol >= kek ? " = True" : " = False") << endl;
      cout << lol << " < " << kek << (lol < kek ? " = True" : " = False") << endl;
      cout << lol << " <= " << kek << (lol <= kek ? " = True" : " = False") << endl;
      break;
    }

    case 4: {
      cout << "\n//-- Summ Test --//\n\n";
      Rational rr;
      for (int i = 1; i < 30; i++) {
        Rational temp(1, i);
        rr = rr + temp;
        cout << rr << " = " << rr.get_value() << endl;
      }
      break;
    }

    case 5: { // shell sort
      int count = 9;
      Rational *arr[count] = {
        new Rational(1,   2),
        new Rational(12,  21),
        new Rational(13,  22),
        new Rational(14,  23),
        new Rational(15,  24),
        new Rational(0,   1),
        new Rational(666, 6),
        new Rational(16,  25),
        new Rational(17,  26)
      };

      cout << "original:\n";
      for (int i = 0; i < count; i++) {
        cout << *(arr[i]) << endl;
      }

      ShellSort(count, arr);
      cout << "sorted:\n";
      for (int i = 0; i < count; i++) {
        cout << *(arr[i]) << endl;
      }
    }
  }
}