// Сделать реализацию vector на шаблонах
// функции:
// vector(size_t size, const T& value)
// push_back
// size
// operator[]
// at (бросает исключения)
// insert(size_t i, const T& value) (бросает исключения)
// erase(size_t i) (бросает исключения)

#include <iostream>
#include <stdexcept>

template <typename T>
class vector {
 private:
  T* data;
  size_t size;
  size_t capacity;

 public:
  vector(size_t size, const T& value) {
    this->size = size;
    this->capacity = size;
    this->data = new T[size];
    for (size_t i = 0; i < size; i++) {
      this->data[i] = value;
    }
  }

  void push_back(const T& value) {
    if (this->size == this->capacity) {
      this->capacity *= 2;
      T* new_data = new T[this->capacity];
      for (size_t i = 0; i < this->size; i++) {
        new_data[i] = this->data[i];
      }
      delete[] this->data;
      this->data = new_data;
    }
    this->data[this->size] = value;
    this->size++;
  }

  size_t get_size() { return this->size; }

  T& operator[](size_t i) { return this->data[i]; }

  T& at(size_t i) {
    if (i >= this->size) {
      throw std::out_of_range("Index out of range");
    }
    return this->data[i];
  }

  void insert(size_t i, const T& value) {
    if (i >= this->size) {
      throw std::out_of_range("Index out of range");
    }
    if (this->size == this->capacity) {
      this->capacity *= 2;
      T* new_data = new T[this->capacity];
      for (size_t j = 0; j < this->size; j++) {
        new_data[j] = this->data[j];
      }
      delete[] this->data;
      this->data = new_data;
    }
    for (size_t j = this->size; j > i; j--) {
      this->data[j] = this->data[j - 1];
    }
    this->data[i] = value;
    this->size++;
  }

  void erase(size_t i) {
    if (i >= this->size) {
      throw std::out_of_range("Index out of range");
    }
    for (size_t j = i; j < this->size - 1; j++) {
      this->data[j] = this->data[j + 1];
    }
    this->size--;
  }

  ~vector() { delete[] this->data; }

  void print() {
    for (size_t i = 0; i < this->size; i++) {
      std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
  }
};
