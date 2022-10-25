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

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

class Notebook {
 private:
  std::map<unsigned, std::string> phonebook;

 public:
  Notebook() = default;

  Notebook(const std::string& filename) { load(filename); }

  void add(const std::string& name, unsigned phone) { phonebook[phone] = name; }

  void erase(const std::string& name) {
    for (auto it = phonebook.begin(); it != phonebook.end(); ++it) {
      if (it->second == name) {
        phonebook.erase(it);
        break;
      }
    }
  }

  std::string& find(unsigned phone) { return phonebook[phone]; }
  unsigned find(const std::string& name) {
    for (auto it = phonebook.begin(); it != phonebook.end(); ++it) {
      if (it->second == name) {
        return it->first;
      }
    }
    return 0;
  }

  friend std::ostream& operator<<(std::ostream& os, const Notebook& nb) {
    for (auto it = nb.phonebook.begin(); it != nb.phonebook.end(); ++it) {
      os << it->first << " " << it->second << std::endl;
    }
    return os;
  }

  void load(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
      std::string name;
      unsigned phone;
      while (file >> phone >> name) {
        phonebook[phone] = name;
      }
    } else {
      throw std::runtime_error("File not found");
    }
  }

  void save(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
      for (auto it = phonebook.begin(); it != phonebook.end(); ++it) {
        file << it->first << " " << it->second << std::endl;
      }
    }
  }
};