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
using namespace std;

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
    Matrix(int size = 1) {
      arr.resize(size);
      for (int i = 0; i < size; i++)
        arr[i].resize(size);
    }
    
    Matrix(vector <vector <double>> a) {
      arr = a;
    }

    Matrix& set(int x, int y, double value) {}
    Matrix& set(vector <vector <double>> a) {}

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

  //TODO: делать проверку на квадратность
  Matrix m4(
    {
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
    }
  );
  m4.print();
}