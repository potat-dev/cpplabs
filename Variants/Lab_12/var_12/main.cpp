// Создайте класс SqrMatrix
// (квадратная матрица с элементами типа double)
// с операциями + - * /, умножения на скаляр
// Размерность матрицы задать в конструкторе

// TODO:
// Используйте приватные поля для данных
// Реализуйте конструктор, который должен устанавливать значения по умолчанию, 
// Реализуйте методы для чтения и записи значений полей (set, get), а также ввода и вывода (перегрузка operator<< и operator>> не требуется)
// Если требуется, напишите конструктор копий, оператор присваивания и деструктор 
// Напишите программу для тестирования вашего класса

#include <vector>
using namespace std;

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
    Matrix(int size = 1) {}
    Matrix(vector <vector <double>> a) {}

    Matrix& set(int x, int y, double value) {}
    Matrix& set(vector <vector <double>> a) {}

    double get(int x, int y) {}

    void print() {}
};

int main() {
  Matrix m;
}