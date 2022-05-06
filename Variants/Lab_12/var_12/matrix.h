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

    Matrix& operator+=(const Matrix& x);
    Matrix& operator-=(const Matrix& x);
    Matrix& operator*=(const Matrix& x);
    
    friend Matrix operator+(Matrix a, const Matrix &b);
    friend Matrix operator-(Matrix a, const Matrix &b);
    friend Matrix operator*(Matrix a, const Matrix &b);
};