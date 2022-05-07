#include <cstdlib> // для exit()
#include "matrix.h"

// class Matrix

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

void Matrix::print() {
  for (int y = 0; y < arr.size(); y++) {
    for (int x = 0; x < arr[y].size(); x++)
      cout << arr[y][x] << " ";
    cout << endl;
  }
  cout << endl;
}

// other functions

unsigned int get_size(vector <vector <double>> arr) {
  unsigned int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (arr[i].size() != size) {
      return 0;
    }
  }
  return size;
}

// преобразования

void swap(double *d1, double *d2) {
  double temp = *d1;
  *d1 = *d2;
  *d2 = temp;
}

Matrix& Matrix::transpose() {
  for (int y = 0; y < this->size() - 1; y++) {
    for (int x = y + 1; x < this->size(); x++) {
      swap(&arr[y][x], &arr[x][y]);
    }
  }
  return *this;
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
      for (int x = 0; x < m.arr.size(); x++) {
        for (int y = 0; y < m.arr.size(); y++) {
          arr[y][x] -= m.arr[y][x];
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

Matrix operator+(Matrix a, const Matrix& b) {
  a += b;
  return a;
}

Matrix operator-(Matrix a, const Matrix& b) {
  a -= b;
  return a;
}

Matrix& Matrix::operator*=(const Matrix& right) {
  unsigned int size = this->size();
  Matrix result(size, 0);
  for (int result_x = 0; result_x < size; result_x++) {
    for (int result_y = 0; result_y < size; result_y++) {
      double summ = 0;
      for (int i = 0; i < size; i++)
        summ += arr[result_y][i] * right.arr[i][result_x];
      result.arr[result_y][result_x] = summ;
    }
  }
  *this = result;
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

Matrix& Matrix::operator/=(const double& n) {
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