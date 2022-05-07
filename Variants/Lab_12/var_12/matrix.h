#pragma once

#include <vector>
#include <iostream>
using namespace std;

unsigned int get_size(vector <vector <double>> arr);

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
    // конструтроры (не лего)
    Matrix(unsigned int size = 1, double def = 0);
    Matrix(vector <vector <double>> temp); 

    // сеттеры
    Matrix& set(unsigned int x, unsigned int y, double value);
    Matrix& set(vector <vector <double>> temp);
    Matrix& set(Matrix& m);

    // геттеры
    double get(unsigned int x, unsigned int y);
    const unsigned int size();

    void print();

    // преобразования

    Matrix& transpose();

    // операторы

    Matrix& operator+=(const Matrix& x); // сложение с матрицей
    Matrix& operator-=(const Matrix& x); // вычитание матрицы
    Matrix& operator*=(const Matrix& x); // умножение на матрицу
    Matrix& operator*=(const double& x); // умножение на скаляр
    Matrix& operator/=(const Matrix& x); // деление на матрицу
    Matrix& operator/=(const double& x); // деление на скаляр
    
    friend Matrix operator+(Matrix a, const Matrix &b);
    friend Matrix operator-(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const double &b);
    friend Matrix operator/(Matrix a, const Matrix &b);
    friend Matrix operator/(Matrix a, const double &b);
};