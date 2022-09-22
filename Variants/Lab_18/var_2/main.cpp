// Реализовать базу данных о людях. Человек (вспомогательный класс Person)
//описывается следующими полями: имя, фамилия, год рождения, пол, номер
//паспорта. Рекомендуется перегрузить для класса Person оператор сравнения.
// load(const std::string& filename)
// save(const std::string& filename)
// operator<< для вывода на экран
// add(const Person& p)
// erase(const Person& p)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
 private:
  string name = "";
  string surname = "";
  int year = 0;
  bool gender = 0;  // 1 woman, 0 man
  int passport = 0;

 public:
  Person()
      : name("Rayan"),
        surname("Gosling"),
        year(1980),
        gender(0),
        passport(420069){};
  Person(string name, string surname, int year, bool gender, int passport) {
    this->name = name;
    this->surname = surname;
    this->year = year;
    this->gender = gender;
    this->passport = passport;
  }

  bool operator==(const Person &p1) {
    return (this->name == p1.name) && (this->surname == p1.surname) &&
           (this->year == p1.year) && (this->gender == p1.gender) &&
           (this->passport == p1.passport);
  }

  friend ostream &operator<<(ostream &out, Person &p) {
    out << p.name << " " << p.surname << " " << p.year << " " << p.gender << " " << p.passport << endl;
    return out;
  }
};

class Database {
 private:
  vector<Person> db;

 public:
  void load(const string &filename) {
    ifstream fin(filename);
    while (!fin.eof()) {
      string name, surname;
      int year, passport;
      bool gender;
      fin >> name >> surname >> year >> gender >> passport;
      db.push_back(Person(name, surname, year, gender, passport));
    }
  }

  void save(const string &filename) {
    ofstream fout(filename);
    for (int i = 0; i < db.size(); i++) {
      fout << db[i];
    }
  }

  void add(const Person &p) { db.push_back(p); }

  friend ofstream &operator<<(ofstream &out, Database &d) {
    for (int i = 0; i < d.db.size(); i++) {
      out << d.db[i];
    }
    return out;
  }

  void erase(const Person &p) {
    for (int i = 0; i < db.size(); i++) {
      if (db[i] == p) {
        db.erase(db.begin() + i);
      }
    }
  }

  friend ostream &operator<<(ostream &out, Database &d) {
    for (int i = 0; i < d.db.size(); i++) {
      out << d.db[i];
    }
    return out;
  }
};

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
  cout << db;

  cout << "After erase" << endl;
  db.erase(Person("Bread", "Pitt", 1963, 0, 420071));
  cout << endl << db;

  cout << "After add" << endl;
  db.add(Person("Andrey", "Kruk", 1963, 1, 666));
  cout << endl << db;

  db.save("db.txt");
  return 0;
}
