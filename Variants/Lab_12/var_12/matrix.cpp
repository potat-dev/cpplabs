#include <cstdlib> // для exit()
#include "matrix.h"

// class Matrix

// конструктор по умолчанию
Matrix::Matrix(unsigned int size, double def) {
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

// конструктор от двумерного массива
Matrix::Matrix(vector <vector <double>> temp):
  Matrix (get_size(temp)) {
    arr = temp;
}

const unsigned int Matrix::size() {
  return arr.size();
}

// сеттеры

Matrix& Matrix::set(unsigned int x, unsigned int y, double value) {
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

// установить новый двумерный массив в матрицу
// важно чтобы он был того же размера
Matrix& Matrix::set(vector <vector <double>> temp) {
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

Matrix& Matrix::set(Matrix& m) {
  this->arr = m.arr;
  return *this;
}

// геттеры

double Matrix::get(unsigned int x, unsigned int y) {
  try {
    if (x < arr.size() && y < arr.size()) {
      return arr[y][x];
    } else {
      throw "Invalid index";
    }
  } catch (const char *s) {
    cerr << "Error in 'get' operator: " << s << endl;
    exit(1);
  }
}

// получение размера двумерного массива (не матрицы)
// если двумерный массив не квадратный - 0
unsigned int get_size(vector <vector <double>> arr) {
  unsigned int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (arr[i].size() != size) {
      return 0;
    }
  }
  return size;
}

void Matrix::print() {
  for (int y = 0; y < arr.size(); y++, cout << endl)
    for (int x = 0; x < arr[y].size(); x++)
      cout << arr[y][x] << " ";
  cout << endl;
}

// преобразования

// унарный минус (смена знаков элементов)
Matrix operator-(const Matrix &m) {
  Matrix temp(m);
  for (int x = 0; x < temp.arr.size(); x++)
    for (int y = 0; y < temp.arr.size(); y++)
      temp.arr[y][x] *= -1;
	return temp;
}

void swap(double *d1, double *d2) {
  double temp = *d1;
  *d1 = *d2;
  *d2 = temp;
}

// транспонирование матрицы
// отзеркаливание относительно главной диагонали
Matrix Matrix::transpose() {
  Matrix temp(*this);
  for (int y = 0; y < this->size() - 1; y++) {
    for (int x = y + 1; x < this->size(); x++) {
      swap(&temp.arr[y][x], &temp.arr[x][y]);
    }
  }
  return temp;
}

// нахождение минора
// это короче матрица с вычеркнутым столбцом с индексом x
// и вычеркнутой строкой с индексом y
Matrix Matrix::minor(int _y, int _x) {
  Matrix temp(arr.size() - 1);
  bool skip_x, skip_y = 0;
  for (int y = 0; y < temp.arr.size(); y++) {
    if (y == _y) skip_y = 1;
    skip_x = 0;
    for (int x = 0; x < temp.arr.size(); x++) {
      if (x == _x) skip_x = 1;
      temp.set(x, y, arr[y + skip_y][x + skip_x]);
    }
  }
  return temp;
}

// определитель матрицы (рекурсивно)
// два базовых случая и рекурсия для матриц >= 3
const double Matrix::determinant() {
  switch (arr.size()) {
    case 1:
      return arr[0][0];

    case 2:
      return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];

    default:
      double det = 0;
      for (int i = 0; i < arr.size(); i++)
        det += (i % 2 ? -1 : 1) * arr[i][0] * this->minor(i, 0).determinant();
      return det;
  }
}

// матрица миноров
// каждый элемент это определитель минора по индексу этого элемента
Matrix Matrix::minor_matrix() {
  Matrix temp(arr.size());
  for (int y = 0; y < arr.size(); y ++) {
    for (int x = 0; x < arr.size(); x++) {
      temp.set(x, y, this->minor(y, x).determinant());
    }
  }
  return temp;
}

// матрица алгебраических дополнений
// просто матрица миноров но с переменой знаков по диагонале
Matrix Matrix::algebraic_additions() {
  Matrix temp = this->minor_matrix();
  for (int x = 0; x < arr.size(); x++) {
    for (int y = 0; y < arr.size(); y++) {
      if ((x + y) % 2) temp.arr[y][x] *= -1;
    }
  }
  return temp;
}

// обратная матрица (самое сложное)
// надо поделить транспонированую матрицу алгебраических
// дополнений на определитель исходной матрицы
Matrix Matrix::inverse() {
  Matrix alg_add_T = this->algebraic_additions().transpose();
  alg_add_T /= this->determinant();
  return alg_add_T;
}

// операторы

Matrix& Matrix::operator+=(const Matrix& m) {
  try {
    if (arr.size() == m.arr.size()) {
      for (int x = 0; x < m.arr.size(); x++) {
        for (int y = 0; y < m.arr.size(); y++) {
          arr[y][x] += m.arr[y][x];
        }
      }
    } else {
      throw "Matrices have different sizes";
    }
  } catch (const char *s) {
    cerr << "Error in + operator: " << s << endl;
    exit(1);
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
  try {
    if (arr.size() == m.arr.size()) {
      *this += -m;
    } else {
      throw "Matrices have different sizes";
    }
  } catch (const char *s) {
    cerr << "Error in - operator: " << s << endl;
    exit(1);
  }
  return *this;
}

Matrix operator+(Matrix a, const Matrix& b) {
  a += b;
  return a;
}

Matrix operator-(Matrix a, const Matrix& b) {
  a -= b;
  return a;
}

Matrix& Matrix::operator*=(const Matrix& right) {
  try {
    if (right.arr.size() == arr.size()) {
      unsigned int size = this->size();
      Matrix result(size, 0);
      for (int result_x = 0; result_x < arr.size(); result_x++) {
        for (int result_y = 0; result_y < arr.size(); result_y++) {
          double summ = 0;
          for (int i = 0; i < size; i++)
            summ += arr[result_y][i] * right.arr[i][result_x];
          result.arr[result_y][result_x] = summ;
        }
      }
      *this = result;
    } else {
      throw "Matrices have different sizes";
    }
  } catch (const char *s) {
    cerr << "Error in * operator: " << s << endl;
    exit(1);
  }
  return *this;
}

Matrix operator*(Matrix a, const Matrix& b) {
  a *= b;
  return a;
}

Matrix& Matrix::operator*=(const double& n) {
  for (int x = 0; x < arr.size(); x++) {
    for (int y = 0; y < arr.size(); y++) {
      arr[y][x] *= n;
    }
  }
  return *this;
}

Matrix operator*(Matrix a, const double &b) {
  a *= b;
  return a;
}

// деление матрицы на матрицу

Matrix& Matrix::operator/=(const Matrix &b) {
  *this *= Matrix(b).inverse();
  // спросить у Линского про оптимизацию этого куска
  // лишнее копирование
  return *this;
}

Matrix operator/(Matrix a, const Matrix &b) {
    a /= b;
    return a;
}

Matrix& Matrix::operator/=(const double& n) {
  // не нужно предупреждать о делении на ноль
  for (int x = 0; x < arr.size(); x++) {
    for (int y = 0; y < arr.size(); y++) {
      arr[y][x] /= n;
    }
  }
  return *this;
}

Matrix operator/(Matrix a, const double &b) {
  a /= b;
  return a;
}