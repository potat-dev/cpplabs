//? Задание:
//  Создайте класс HugeInt, который хранит в 40-элементном массиве цифр целые числа разрядностью до 40 знаков.
//  Разрядность указать в конструкторе. Предусмотреть функции сложения, вычитания, сравнения и проверки на 0.

/// TODO ///
//? исправить:
//  расставить const
//  сет и гет для всех полей
//  узнавать знак числа
//  менять знак числа
//  узнавать позицию на разряде
//  менять позицию на разряде
//  урезать размер числа, чтобы не было нулей
//? доп:
//  перегрузка операторов
//  |- операторы сравнения
//  |- операторы вывода на экран
//  |- математические операторы
//  умножение
//  нахождение остатка от деления

#include "HugeInt.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  HugeInt a, b("7"), s;

  wcout << L"Введите первое число: ";
  cin >> a;
  wcout << L"Введите второе число: ";
  cin >> b;

  while (1) {
    int num;
    wcout << L"С каким числом вы хотите работать (0 - a, 1 - b): " << endl;
    cin >> num;

    wcout << L"Введите что вам нужно сделать:" << endl;
    wcout << L"1 - Менять знак числа" << endl;
    wcout << L"2 - Менять позицию на разряде" << endl;
    wcout << L"0 - Выйти" << endl;

    cout  << ">> ";
    int to_do;
    cin >> to_do;

    switch (to_do) {
      case 1: {
        wcout << L"Исходное число: ";
        cout << (num ? b : a) << endl;
        (num ? b : a) = -(num ? b : a);
        wcout << L"Измененное число: ";
        cout << (num ? b : a) << endl;
        break;
      }

      case 2: {
        wcout << L"Исходное число: ";
        cout << (num ? b : a) << endl;
        wcout << L"Введите индекс и цифру: ";
        int index, digit;
        cin >> index >> digit;
        (num ? b : a).set_digit(index, digit);
        wcout << L"Измененное число: ";
        cout << (num ? b : a) << endl;
        break;
      }

      case 0: {
        goto end;
      }
    }
  }
  
  end:
  
  a.set_minus(!a.has_minus()); //-- изменение знака
  a.set_digit(0, 2);
  cout << a << " " << a.get_digit(0) << endl;

  cout << endl;
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

  s = a + b;
  cout << "Summ = " << s << endl;

  s = -s;
  cout << "-s = " << s << endl;

  // проверка умножения

  HugeInt test_mult = a * b;
  cout << "a * b = " << test_mult << endl;

  HugeInt test_mod = a % b;
  cout << "a % b = " << test_mod << endl;

  return 0;
}