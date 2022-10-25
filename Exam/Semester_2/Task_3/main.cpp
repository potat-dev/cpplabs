#include <iostream>
#include <string.h>
using namespace std;

class Vector {
  private:
    int *arr;
    size_t size;

  public:
    Vector(size_t size);
    Vector(Vector& v);
    ~Vector();
    Vector& operator=(Vector& v);
    Vector& set(size_t index, int value);
    void print();
};

Vector::Vector(size_t size) {
  this->size = size;
  arr = new int[size];
}

Vector::Vector(Vector& v) {
  this->size = v.size;
  arr = new int[size];
  memcpy(arr, v.arr, sizeof(int) * size);
}

Vector& Vector::operator=(Vector& v) {
  if (&v == this) return *this; // присваивание самому себе
  this->size = v.size;
  delete[] arr;
  arr = new int[size];
  memcpy(arr, v.arr, sizeof(int) * size);
  return *this;
}

Vector::~Vector() {
  delete[] arr;
}

Vector& Vector::set(size_t index, int value) {
  arr[index] = value;
  return *this;
}

void Vector::print() {
  for (size_t i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  cout << endl;
}

int main() {
  Vector a(4);
  a.set(0, 0).set(1, 1).set(2, 42).set(3, 618).print();

  Vector b(a);
  b.print();

  a.set(0, 777).print();
  b.print();

  b = a;
  b.print();
}