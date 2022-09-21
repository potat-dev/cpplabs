// Реализовать записную книжку с поиском по телефону и по имени
// Данные необходимо загружать из текстового файла

// функции:
// Notebook(const std::string& filename) - конструктор из файла
// add(const std::string &name, unsigned phone)
// erase(const std::string &name)
// std::string& find(unsigned phone)
// unsigned find(const std:string& name)
// operator<< для вывода на экран
// load(const std::string& filename)
// save(const std::string& filename)

// написать программу для тестирования функций класса

#include <iostream>
#include <stdexcept>

#include "notebook.hpp"

using namespace std;

int main() {
  Notebook nb;

  try {
    nb.load("notebook.txt");
  } catch (std::runtime_error& e) {
    cout << e.what() << endl;
    cout << "Creating new notebook:" << endl;
    nb.add("Ivan", 123456);
    nb.add("Petr", 654321);
    nb.add("Oleg", 214365);
    nb.add("Vlad", 987654);
  }

  cout << nb << endl;
  nb.save("notebook.txt");

  nb.erase("Ivan");
  cout << nb << endl;
  cout << nb.find(654321) << endl;
  cout << nb.find("Petr") << endl;
  return 0;
}