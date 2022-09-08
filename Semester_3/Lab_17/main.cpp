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

// доп: сохранение в файл и загрузка из файла
// с исключениями, причем сохранять в json

#include <iostream>
#include "exception.h"
#include "matrix.h"
using namespace std;

int main() {
  Matrix<int> m(2, 2);
  m.set(0, 0, 1);
  m.set(0, 1, 2);
  m.set(1, 0, 3);
  m.set(1, 1, 4);
  cout << "m:\n";
  m.print();

  Matrix<int> m2(m);
  cout << "m2:\n";
  m2.print();

  Matrix<int> m3(5, 5);
  cout << "m3:\n";
  m3.print();

  m3 = m2;
  cout << "m3 = m2:\n";
  m3.print();

  Matrix<int> m4(2, 2);
  m4.set(0, 0, 1);
  m4.set(0, 1, 2);
  m4.set(1, 0, 3);
  m4.set(1, 1, 4);
  cout << "m4:\n";
  m4.print();

  Matrix<int> m5(2, 2);
  m5.set(0, 0, 1);
  m5.set(0, 1, 2);
  m5.set(1, 0, 3);
  m5.set(1, 1, 4);
  m5.print();

  Matrix<int> m6 = m4.sum(m5);
  m6.print();

  cout << "m6.get(0, 0): " << m6.get(0, 0) << endl;
  cout << "m6.get(0, 1): " << m6.get(0, 1) << endl;
  cout << "m6.get(1, 0): " << m6.get(1, 0) << endl;
  cout << "m6.get(1, 1): " << m6.get(1, 1) << endl;
  cout << endl;

  Matrix<int> m7(5, 7);
  for (size_t i = 0; i < m7.rows(); i++)
    for (size_t j = 0; j < m7.columns(); j++)
      m7.set(i, j, rand() % 100);

  // save to file matrix.json
  m7.save("matrix.json");

  // testing exceptions
  /*
  try {
    cout << m6.get(2, 2) << endl;
    cout << "test after exception in get()" << endl;
  } catch (MatrixException& e) {
    cerr << e << endl;
    throw e;
  }
  
  try {
    m6.set(2, 2, 42);
    cout << "test after exception in set()" << endl;
  } catch (MatrixException& e) {
    cerr << e << endl;
    throw e;
  }

  try {
    m6 = m2.sum(m3);
    cout << "test after exception in sum()" << endl;
  } catch (MatrixException& e) {
    cerr << e << endl;
    throw e;
  }
  */
  return 0;
}