#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "exception.h"

// pacman -S mingw-w64-x86_64-nlohmann-json
#include <nlohmann/json.hpp>
using json = nlohmann::json;

template <typename T>
class Matrix {
  private:
    size_t rows_;
    size_t columns_;
    T* data_;
  
  public:
    Matrix(size_t row, size_t column, T value = T()) {
      rows_ = row;
      columns_ = column;
      data_ = new T[rows_ * columns_];
      for (size_t i = 0; i < rows_ * columns_; i++) {
        data_[i] = value;
      }
    }

    Matrix(const Matrix& m) {
      rows_ = m.rows_;
      columns_ = m.columns_;
      data_ = new T[rows_ * columns_];
      for (size_t i = 0; i < rows_ * columns_; i++) {
        data_[i] = m.data_[i];
      }
    }

    // constructor from json file
    Matrix(string file) {
      ifstream input(file);
      if (!input) throw MatrixException("Can't open file for load");
      try {
        json j = json::parse(input);
        rows_ = j["rows"];  
        columns_ = j["columns"];
        data_ = new T[rows_ * columns_];
        for (size_t i = 0; i < rows_ * columns_; i++) {
          data_[i] = j["data"][i];
        }
      } catch (json::parse_error& e) {
        throw MatrixException("Can't parse json");
      }
    }

    ~Matrix() {
      delete[] data_;
    }

    void load(string file) {
      this->~Matrix();
      ifstream input(file);
      if (!input) throw MatrixException("Can't open file for load");
      try {
        json j = json::parse(input);
        rows_ = j["rows"];  
        columns_ = j["columns"];
        data_ = new T[rows_ * columns_];
        for (size_t i = 0; i < rows_ * columns_; i++) {
          data_[i] = j["data"][i];
        }
      } catch (json::parse_error& e) {
        throw MatrixException("Can't parse json");
      }
    }

    void save(string file, int indent = 2) {
      ofstream output(file);
      if (!output) throw MatrixException("Can't open file for save");
      json j;
      j["rows"] = rows_;
      j["columns"] = columns_;
      for (size_t i = 0; i < rows_ * columns_; i++) {
        j["data"].push_back(data_[i]);
      }
      output << std::setw(indent) << j << endl;
    }

    void set(size_t row, size_t column, T value) {
      if (row >= rows_ || column >= columns_) {
        throw MatrixException("Out of range");
      }
      data_[row * columns_ + column] = value;
    }

    T& get(size_t row, size_t column) {
      if (row >= rows_ || column >= columns_) {
        throw MatrixException("Out of range");
      }
      return data_[row * columns_ + column];
    }

    size_t rows() const {
      return rows_;
    }

    size_t columns() const {
      return columns_;
    }

    Matrix sum(const Matrix& m) {
      if (rows_ != m.rows_ || columns_ != m.columns_) {
        throw MatrixException("Different sizes");
      }
      Matrix result(rows_, columns_);
      for (size_t i = 0; i < rows_ * columns_; i++) {
        result.data_[i] = data_[i] + m.data_[i];
      }
      return result;
    }
  
    Matrix& operator=(const Matrix& m) {
      if (this == &m) {
        return *this;
      }
      delete[] data_;
      rows_ = m.rows_;
      columns_ = m.columns_;
      data_ = new T[rows_ * columns_];
      for (size_t i = 0; i < rows_ * columns_; i++) {
        data_[i] = m.data_[i];
      }
      return *this;
    }

    void print() {
      for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < columns_; j++) {
          std::cout << data_[i * columns_ + j] << " ";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
};