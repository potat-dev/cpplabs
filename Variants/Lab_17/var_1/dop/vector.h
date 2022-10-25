// Сделать реализацию vector на шаблонах

// функции:
// vector(size_t size, const T& value)
// push_back(const T& value)
// size()
// operator[]
// at(size_t i) (бросает исключения)
// insert(size_t i, const T& value) (бросает исключения)
// erase(size_t i) (бросает исключения)

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
 private:
  T* data;
  size_t size;
  size_t capacity;

 public:
  Vector(size_t size, const T& value) {
    this->size = size;
    this->capacity = size;
    this->data = new T[size];  // выделяем память
    for (size_t i = 0; i < size; i++) {
      this->data[i] = value;  // заполняем
    }
  }

  void push_back(const T& value) {
    if (this->size == this->capacity) {  // если массив заполнен
      this->capacity *= 2;  // увеличиваем его в 2 раза
      T* new_data = new T[this->capacity];  // создаем новый массив
      for (size_t i = 0; i < this->size; i++) {
        new_data[i] = this->data[i];  // копируем данные
      }
      delete[] this->data;    // удаляем старый массив
      this->data = new_data;  // меняем указатель
    }
    this->data[this->size] = value;  // добавляем элемент
    this->size++;                    // увеличиваем размер
  }

  size_t get_size() { return this->size; }  // возвращаем размер массива

  T& operator[](size_t i) { return this->data[i]; }  // перегрузка оператора []

  T& at(size_t i) {
    if (i >= this->size) {  // если индекс больше размера массива
      throw std::out_of_range("Index out of range");  // бросаем исключение
    }
    return this->data[i];  // возвращаем элемент
  }

  void insert(size_t i, const T& value) {
    if (i >= this->size) {  // если индекс больше размера массива
      throw std::out_of_range("Index out of range");  // бросаем исключение
    }
    if (this->size == this->capacity) {  // если массив заполнен
      this->capacity *= 2;  // увеличиваем его в 2 раза
      T* new_data = new T[this->capacity];  // создаем новый массив
      for (size_t j = 0; j < this->size; j++) {
        new_data[j] = this->data[j];  // копируем данные
      }
      delete[] this->data;    // удаляем старый массив
      this->data = new_data;  // меняем указатель
    }
    for (size_t j = this->size; j > i; j--) {
      this->data[j] = this->data[j - 1];  // сдвигаем элементы
    }
    this->data[i] = value;  // вставляем элемент
    this->size++;  // увеличиваем размер массива
  }

  void erase(size_t i) {
    if (i >= this->size) {  // если индекс больше размера массива
      throw std::out_of_range("Index out of range");  // бросаем исключение
    }
    for (size_t j = i; j < this->size - 1; j++) {
      this->data[j] = this->data[j + 1];  // сдвигаем элементы
    }
    this->size--;  // уменьшаем размер массива
  }

  ~Vector() { delete[] this->data; }  // деструктор

  void print() {
    for (size_t i = 0; i < this->size; i++) {
      std::cout << this->data[i] << " ";  // выводим элементы массива
    }
    std::cout << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& out, const Vector<T>& v) {
    for (size_t i = 0; i < v.size; i++) {
      out << v.data[i] << " ";  // выводим элементы массива
    }
    return out;
  }

  // поразрядное сложение векторов
  Vector<T> operator+(const Vector<T>& v) {
    if (this->size != v.size) {  // если размеры массивов не равны
      throw std::out_of_range(
          "Vectors have different sizes");  // бросаем исключение
    }
    Vector<T> result(this->size, 0);  // создаем вектор для результата
    for (size_t i = 0; i < this->size; i++) {
      result.data[i] = this->data[i] + v.data[i];
    }
    return result;  // возвращаем результат
  }

  // поразрядное вычитание векторов
  Vector<T> operator-(const Vector<T>& v) {
    if (this->size != v.size) {  // если размеры массивов не равны
      throw std::out_of_range(
          "Vectors have different sizes");  // бросаем исключение
    }
    Vector<T> result(this->size, 0);  // создаем вектор для результата
    for (size_t i = 0; i < this->size; i++) {
      result.data[i] = this->data[i] - v.data[i];  // вычитаем элементы
    }
    return result;  // возвращаем результат
  }
};
