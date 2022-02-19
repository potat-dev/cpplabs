// Создайте класс HugeInt, который хранит в 40-элементном массиве
// цифр целые числа разрядностью до 40 знаков
// Разрядность указать в конструкторе.
// Предусмотреть функции сложения, вычитания, сравнения и проверки на 0

#include <iostream>
#include <string>

using namespace std;

class HugeInt {
  private:
    int arr[5];
    int test;

  public:
    string str = "hello";
    int arr_2[5];
    int pub = 42;

    void print() {
      for (char i = 0; i < 5; i++)
        printf(i < 4 ? "%d, " : "%d", arr[i]);

      printf("\ntest: %d\n", test);
    }

    void set(int *a) {
      for (char i = 0; i < 5; i++) arr[i] = a[i];
    }
};

class Test {
  public:
    int arr[5];
    int test = 42;

    void print() {
      for (char i = 0; i < 5; i++)
        printf(i < 4 ? "%d, " : "%d", arr[i]);
      printf("\ntest: %d\n", test);
    }
  
  // private:
  //   void test() {
  //     cout << "test lol" << endl;
  //   };
};

int main() {
  string hello = "hello";
  int arr[5] = {3, 4, 5, 6, 7};

  Test test_1 {{1, 2, 3, 4, 5}, 4242};
  Test test_2;

  test_1.print();
  test_2.print();
  test_2.arr[0] = 42;

  HugeInt h;
  cout << h.str << endl;
  h.set(arr);
  h.print();
}

// Используйте приватные поля для данных,
// определите конструктор, который должен содержать значения по умолчанию,
// напишите методы установки и извлечения значений (set, get),
// выполнения операций ввода и вывода значения объекта созданного класса.
// Напишите конструктор копий, оператор присваивания, деструктор.
// Напишите программу для тестирования вашего класса