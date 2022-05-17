//? Задание:
//  Создайте класс HugeInt, который хранит в 40-элементном массиве цифр целые числа разрядностью до 40 знаков.
//  Разрядность указать в конструкторе. Предусмотреть функции сложения, вычитания, сравнения и проверки на 0.

/// TODO ///
//? НЕ ДОП:
//* расставить const
//* сет и гет для всех полей
//* узнавать знак числа
//* менять знак числа
//* узнавать позицию на разряде
//* менять позицию на разряде
//* урезать размер числа, чтобы не было нулей
//? ДОП:
//  перегрузка операторов
//* - операторы сравнения
//* - операторы вывода на экран
//* - математические операторы
//  умножение
//  нахождение остатка от деления

#include "HugeInt.h"
using namespace std;

int main() {
  HugeInt a, b, s;
  a.print_full();
  a.print();

  a.set("1000");
  b.set("7");
  a.print_full();
  a.print();

  if (a.check_zero()) {
    cout << a << " - its zero " << endl;
  } else {
    cout << a << " - not zero " << endl;
  }

  if (b.check_zero()) {
    cout << b << " - its zero " << endl;
  } else {
    cout << b << " - not zero " << endl;
  }

  if (a > b) {
    cout << a << " > " << b << endl;
  } else if (a < b) {
    cout << a << " < " << b << endl;
  } else if (a == b) {
    cout << a << " = " << b << endl;
  }

  s = a - b;
  cout << "Difference = " << s << endl;
  s.print_full();
  s.print();
  s.shrink_to_fit();
  s.print();

  s = a + b;
  cout << "Summ = " << s << endl;

  s = -s;
  cout << s << endl;
  s.shrink_to_fit();
  s.print();

  return 0;
}