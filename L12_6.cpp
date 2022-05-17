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
//  - математические операторы
//  умножение
//  нахождение остатка от деления

#include "HugeInt.h"
using namespace std;

int main() {
  HugeInt a;
  HugeInt b;
  HugeInt s;
  a.print_full();
  a.print();

  a.set("1000");
  b.set("7");
  a.print_full();
  a.print();

  if (a.check_zero()) {
    cout << a.get() << " - its zero " << endl;
  } else {
    cout << a.get() << " - not zero " << endl;
  }

  if (b.check_zero()) {
    cout << b.get() << " - its zero " << endl;
  } else {
    cout << b.get() << " - not zero " << endl;
  }

  if (a > b) {
    cout << a.get() << " > " << b.get() << endl;
  } else if (a < b) {
    cout << a.get() << " < " << b.get() << endl;
  } else if (a == b) {
    cout << a.get() << " = " << b.get() << endl;
  }

  s = a.dif(b);
  cout << "Difference = " << s.get() << endl;
  s.print_full();
  s.print();
  s.shrink_to_fit();
  s.print();

  s = a.sum(b);
  cout << "Summ = " << s.get() << endl;

  s = -s;
  cout << s.get() << endl;
  s.shrink_to_fit();
  s.print();

  return 0;
}