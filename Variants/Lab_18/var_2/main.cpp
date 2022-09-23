// Реализовать базу данных о людях. Человек (вспомогательный класс Person)
// описывается следующими полями: имя, фамилия, год рождения, пол, номер
// паспорта. Рекомендуется перегрузить для класса Person оператор сравнения

// load(const std::string& filename)
// save(const std::string& filename)
// operator<< для вывода на экран
// add(const Person& p)
// erase(const Person& p)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "database.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Database db;
  db.add(Person("Rayan", "Gosling", 1980, 0, 420069));
  db.add(Person("Angelina", "Jolie", 1975, 1, 420070));
  db.add(Person("Bread", "Pitt", 1963, 0, 420071));
  db.add(Person("Leonardo", "DiCaprio", 1974, 0, 420072));
  db.add(Person("Scarlett", "Johansson", 1984, 1, 420073));
  db.add(Person("Tom", "Cruise", 1962, 0, 420074));
  db.add(Person("Jennifer", "Lawrence", 1990, 1, 420075));
  db.add(Person("Emma", "Watson", 1990, 1, 420076));
  cout << db << endl;

  cout << "After erase" << endl;
  db.erase(Person("Bread", "Pitt", 1963, 0, 420071));
  cout << db << endl;

  cout << "After add" << endl;
  db.add(Person("Andrey", "Kruk", 1963, 1, 666));
  cout << db;

  db.save("db.txt");
  return 0;
}
