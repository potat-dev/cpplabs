// Создайте класс HugeInt, который хранит в 40-элементном
// массиве цифр целые числа разрядностью до 40 знаков
// Разрядность указать в конструкторе

// TODO:
// Предусмотреть функции + - == < <= > >= и проверки на 0
// Используйте приватные поля для данных
// определите конструктор, который должен содержать значения по умолчанию
// напишите методы установки и извлечения значений (set, get)
// выполнения операций ввода и вывода значения объекта созданного класса
// Напишите конструктор копий, оператор присваивания, деструктор
// Напишите программу для тестирования вашего класса

// доп: перегрузить операторы считывания/записи длинного числа из/в текстовый файл

// #define DOP

#include "HugeInt.h"

using namespace std;

#ifndef DOP

  int main() {
    HugeInt test("618");   cout << "init 618: " << test << endl;
    HugeInt test2("618");  cout << "init 618: " << test2 << endl;
    HugeInt test3("619");  cout << "init 619: " << test3 << endl;
    HugeInt test4("-618"); cout << "init -618: " << test4 << endl;
  
    cout << "618 == 618  : " << (test == test2) << endl;
    cout << "618 == 619  : " << (test == test3) << endl;
    cout << "618 == -618 : " << (test == test4) << endl;
    
    cout << "618 != 618  : " << (test != test2) << endl;
    cout << "618 != 619  : " << (test != test3) << endl;
    cout << "618 != -618 : " << (test != test4) << endl;
  
    cout << "618 < 618  : " << (test < test2) << endl;
    cout << "618 < 619  : " << (test < test3) << endl;
    cout << "618 < -618 : " << (test < test4) << endl;
  
    cout << "618 <= 618  : " << (test <= test2) << endl;
    cout << "618 <= 619  : " << (test <= test3) << endl;
    cout << "618 <= -618 : " << (test <= test4) << endl;
  
    cout << "618 > 618  : " << (test > test2) << endl;
    cout << "618 > 619  : " << (test > test3) << endl;
    cout << "618 > -618 : " << (test > test4) << endl;
  
    cout << "618 >= 618  : " << (test >= test2) << endl;
    cout << "618 >= 619  : " << (test >= test3) << endl;
    cout << "618 >= -618 : " << (test >= test4) << endl;
  
    HugeInt lol("42");
    unsigned int kek = 42;
    cout << "42 == 42 : " << (lol == (HugeInt) kek) << endl;
  
    HugeInt lol_copy(lol);
    HugeInt lol_copy_invert(lol, true);
    cout << "42 == copy 42 : " << (lol == lol_copy) << endl;
    cout << "42 == copy -42 : " << (lol == lol_copy_invert) << endl;
    cout << "42 < copy -42 : " << (lol < lol_copy_invert) << endl;
    cout << "42 > copy -42 : " << (lol > lol_copy_invert) << endl;
  
    HugeInt zero_1(0);
    HugeInt zero_2("0");
    cout << "zero 1 == 0 : " << zero_1.is_zero() << endl;
    cout << "zero 2 == 0 : " << zero_2.is_zero() << endl;
    cout << "42 == 0 : " << lol.is_zero() << endl;
  
    HugeInt in_test;
    cout << "enter HugeInt: ";
    cin >> in_test;
    cout << "in_test:  " << in_test << endl;
    HugeInt out_test(in_test);
    cout << "out_test: " << out_test << endl;
  
    cout << "test: " << test << endl;
    test = "123456789";
    cout << "test: " << test << endl;
    test = 987654321;
    cout << "test: " << test << endl;
    test = lol;
    cout << "test: " << test << endl;
  
    cout << test << " to str: " << test.to_str() << endl;
  
    test = -test;
    cout << test << " to str: " << test.to_str() << endl;
  
    // проверка операторов + -
    // НЕ РАБОТАЕТ, ИСПРАВИТЬ
    cout << "\n+ / - operators test\n" << endl;
    HugeInt a, b;
  
    a = 618; b = 42;
    cout << "618 + 42 = " << (a + b) << endl;
    cout << "618 - 42 = " << (a - b) << endl;
  
    a = -618; b = 42;
    cout << "-618 + 42 = " << ((-a) + b) << endl;
    cout << "-618 - 42 = " << ((-a) - b) << endl;
  
    a = 618; b = -42;
    cout << "618 + -42 = " << (a + (-b)) << endl;
    cout << "618 - -42 = " << (a - (-b)) << endl;
  
    a = -618; b = -42;
    cout << "-618 + -42 = " << ((-a) + (-b)) << endl;
    cout << "-618 - -42 = " << ((-a) - (-b)) << endl;
  }

#else

  int main() {
    ifstream input("input.txt");

    HugeInt test(42);
    cout << "init 42: " << test << endl;

    input >> test;
    cout << "from file: " << test << endl;

    HugeInt test2;
    input >> test2;
    cout << "from file: " << test2 << endl;

    input.close();

    ofstream output("output.txt");
    output << test;
    output << endl << test2;

    output.close();
  }

#endif



