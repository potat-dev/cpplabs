// Создайте класс SqrMatrix
// (квадратная матрица с элементами типа double)
// с операциями + - * /, умножения на скаляр
// Размерность матрицы задать в конструкторе

// TODO:
//* Используйте приватные поля для данных
//* Реализуйте конструктор, который должен устанавливать значения по умолчанию, 
// Реализуйте методы для чтения и записи значений полей (set, get), а также ввода и вывода (перегрузка operator<< и operator>> не требуется)
// Если требуется, напишите конструктор копий, оператор присваивания и деструктор 
// Напишите программу для тестирования вашего класса

#include <vector>
#include <iostream>
#include <cstdlib> // для exit()

using namespace std;

unsigned int get_size(vector <vector <double>> arr) {
  unsigned int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (arr[i].size() != size) {
      return 0;
    }
  }
  return size;
}

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
    Matrix(unsigned int size = 1, double def = 0) {
      try {
        if (size > 0) {
          arr.resize(size);
          for (int i = 0; i < size; i++) {
            arr[i].resize(size);
            if (def) {
              fill(arr[i].begin(), arr[i].end(), def);
            }
          }
        } else {
          throw "Matrix is not square";
        }
      } catch (const char *s) {
        cerr << "Error in class constructor: " << s << endl;
        exit(1);
      }
    }
    
    Matrix(vector <vector <double>> temp) : Matrix (get_size(temp)) {
      arr = temp;
    }
    
    const unsigned int size() {
      return arr.size();
    }

    Matrix& set(unsigned int x, unsigned int y, double value) {
      try {
        if (x < arr.size() && y < arr.size()) {
          arr[y][x] = value;
        } else {
          throw "Invalid index";
        }
      } catch (const char *s) {
        cerr << "Error in 'set' operator: " << s << endl;
        exit(1);
      }
      return *this;
    }

    Matrix& set(vector <vector <double>> temp) {
      // TODO: сделать присваивание матрицы другого разера
      try {
        if (get_size(temp) == arr.size()) {
          arr = temp;
        } else {
          throw "Target matrix has different size";
        }
      } catch (const char *s) {
        cerr << "Error in 'set' operator: " << s << endl;
        exit(1);
      }
      return *this;
    }

    Matrix& set(Matrix& m) {
      this->arr = m.arr;
    }

    double get(int x, int y) {}

    void print() {
      for (int y = 0; y < arr.size(); y++) {
        for (int x = 0; x < arr[y].size(); x++)
          cout << arr[y][x] << " ";
        cout << endl;
      }
      cout << endl;
    }
};

int main() {
  Matrix m1;
  m1.print();

  Matrix m2(10);
  m2.print();

  Matrix m3(
    {
      {1, 2, 3, 4},
      {1, 2, 3, 4},
      {1, 2, 3, 4},
      {1, 2, 3, 4},
    }
  );
  m3.print();

  Matrix m4(m3);
  m4.print();

  Matrix m5(
    {
      {1, 2},
      {3, 4}
    }
  );
  m5.print();

  m5 = m3;
  m5.print();

  /* 
  // Error in class constructor: Matrix is not square
  Matrix m6(
    {
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
    }
  );
  m6.print();
  */

  Matrix m7(5, 0.01);
  for (int i = 0; i < m7.size(); i++)
    m7.set(i, i, 9.99);
  
  m7.set(4, 2, 3.14);
  m7.print();

  /*
  // Error in 'set' operator: Invalid index
  m7.set(m7.size(), m7.size() + 1, 0);
  m7.print();
  */

  m7.set(
    {
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5}
    }
  );
  m7.print();

  /*
  // Error in 'set' operator: Target matrix has different size
  m7.set(
    {
      {1, 2},
      {3, 4}
    }
  );
  m7.print();
  */
  
  m7.set(0, 0, 0)
    .set(0, m7.size()-1, 0)
    .set(m7.size()-1, 0, 0)
    .set(m7.size()-1, m7.size()-1, 0);
  m7.print();

  Matrix m8(3, 0.1);
  m8.print();

  m8.set(
    {
      {9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}
    }
  ).set(2, 2, 0);
  m8.print();

  Matrix m9(3);
  m9.set(m8).set(2, 2, 1);
  m9.print();
}