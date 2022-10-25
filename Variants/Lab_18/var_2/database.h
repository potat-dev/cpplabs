#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
 private:
  string name;
  string surname;
  int year = 0;
  bool gender = 0;  // 1 - woman, 0 - man
  int passport = 0;

 public:
  Person();
  Person(string name, string surname, int year, bool gender, int passport);
  friend ostream &operator<<(ostream &out, Person &p);
  bool operator==(const Person &p1);
};

class Database {
 private:
  vector<Person> db;

 public:
  void load(const string &filename);
  void save(const string &filename);
  void add(const Person &p);
  void erase(const Person &p);
  friend ostream &operator<<(ostream &out, Database &d);
  friend ofstream &operator<<(ofstream &out, Database &d);
};