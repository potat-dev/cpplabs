// Сделать реализацию матрицы на шаблонах
// Методы set, get, sum бросают исключения

// Matrix(size_t row, size_t column) // конструктор
// set()                             // устанавливает значение в ячейку
// get()                             // возвращает значение по индексу
// rows()                            // количество строк
// сolumns()                         // количество столбцов
// Matrix sum(const Matrix& m)       // сумма матриц

// реализовать конструктор копий и оператор присваивания
// В main должно быть продемонстрировано, что шаблонный класс работает

#include <iostream>

#include "exception.h"
#include "matrix.h"

using namespace std;

struct Point {
  int x, y, z;

  friend ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << " " << p.y << " " << p.z << ")";
    return os;
  }
};

int main() {
  Matrix<Point> mPoint(3, 3);
  cout << "Matrix<Point> 3x3 before set:" << endl;
  mPoint.print();

  mPoint.set(0, 0, {1, 2, 3});
  mPoint.set(0, 1, {4, 5, 6});
  mPoint.set(0, 2, {7, 8, 9});
  mPoint.set(1, 0, {10, 11, 12});
  mPoint.set(1, 1, {13, 14, 15});
  mPoint.set(1, 2, {16, 17, 18});
  mPoint.set(2, 0, {19, 20, 21});
  mPoint.set(2, 1, {22, 23, 24});
  mPoint.set(2, 2, {25, 26, 27});

  cout << "Matrix<Point> 3x3 after set:" << endl;
  mPoint.print();

  Matrix<int> m1(3, 3);
  m1.set(0, 0, 1);
  m1.set(0, 1, 2);
  m1.set(1, 0, 3);
  m1.set(1, 1, 4);
  cout << "Matrix<int> m1(3, 3):" << endl;
  m1.print();

  Matrix<int> m2(m1);
  cout << "m2 (copy of m1):\n";
  m2.print();

  Matrix<int> m3(5, 5);
  cout << "m3 (default):\n";
  m3.print();

  m3 = m2;
  cout << "after m3 = m2:\n";
  m3.print();

  Matrix<int> a(2, 2);
  a.set(0, 0, 1);
  a.set(0, 1, 2);
  a.set(1, 0, 3);
  a.set(1, 1, 4);
  cout << "first term:" << endl;
  a.print();

  Matrix<int> b(2, 2);
  b.set(0, 0, 1);
  b.set(0, 1, 2);
  b.set(1, 0, 3);
  b.set(1, 1, 4);
  cout << "second term:" << endl;
  b.print();

  Matrix<int> sum = a.sum(b);
  cout << "sum:" << endl;
  sum.print();

  cout << "sum.get(0, 0): " << sum.get(0, 0) << endl;
  cout << "sum.get(0, 1): " << sum.get(0, 1) << endl;
  cout << "sum.get(1, 0): " << sum.get(1, 0) << endl;
  cout << "sum.get(1, 1): " << sum.get(1, 1) << endl;
  cout << endl;

  Matrix<int> forSave(5, 7);
  for (size_t i = 0; i < forSave.rows(); i++)
    for (size_t j = 0; j < forSave.columns(); j++)
      forSave.set(i, j, rand() % 100);
  forSave.print();

  // testing exceptions

  try {
    cout << a.get(2, 2) << endl;
    cout << "test after exception in get()" << endl;
  } catch (MatrixException& e) {
    cerr << e << endl;
    // throw e; // for program termination
  }

  try {
    a.set(2, 2, 42);
    cout << "test after exception in set()" << endl;
  } catch (MatrixException& e) {
    cerr << e << endl;
    // throw e; // for program termination
  }

  try {
    Matrix<int> test = a.sum(m1);
    test.print();
    cout << "test after exception in sum()" << endl;
  } catch (MatrixException& e) {
    cerr << e << endl;
    // throw e; // for program termination
  }

  return 0;
}