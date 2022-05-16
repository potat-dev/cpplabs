/*
  Создайте класс HugeInt, который хранит в 40-элементном массиве цифр целые числа разрядностью до 40 знаков.
  Разрядность указать в конструкторе. Предусмотреть функции сложения, вычитания, сравнения и проверки на 0.

  1) НЕ ДОП:
     расставить const
     сет и гет для всех полей
     узнавать знак числа
     менять знак числа
     узнавать позицию на разряде
     менять позицию на разряде
     урезать размер числа, чтобы не было 0

  2) ДОП:
     перегрузка операторов
     умножение
     нахождение остатка от деления
*/

#include "HugeInt.h"
using namespace std;

int main() {
  HugeInt a;
  HugeInt b;
  HugeInt s;

  a.set("1000");
  b.set("7");

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

  if (a.compare(b) == 1) {
    cout << a.get() << " > " << b.get() << endl;
  } else if (a.compare(b) == -1) {
    cout << a.get() << " < " << b.get() << endl;
  } else if (a.compare(b) == 0) {
    cout << a.get() << " = " << b.get() << endl;
  }

  s = a.dif(b);
  cout << "Difference = " << s.get() << endl;
  
  s = a.sum(b);
  cout << "Summ = " << s.get() << endl;

  return 0;
}