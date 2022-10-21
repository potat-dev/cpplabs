#pragma once

#include <string>
#include <iostream>
using namespace std;

class MatrixException {
  private:
    string msg;

  public:
    MatrixException(const string &msg): msg(msg) {};
    friend ostream& operator<<(ostream& out, const MatrixException& e) {
      out << "MatrixException: " << e.msg;
      return out;
    }
};