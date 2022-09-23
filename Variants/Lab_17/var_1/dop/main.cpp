#include <iostream>

#include "vector.h"


using namespace std;

struct Point {
  int x;
  int y;
  int z;

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
  }
};

int main() {
  Vector<int> v(5, 0);
  for (int i = 0; i < 10; i++) v.push_back(i);
  cout << v << endl;

  Vector<Point> v2(2, {0, 0, 0});
  for (int i = 0; i < 10; i++) v2.push_back({i, i, i});
  cout << v2 << endl << endl;

  // test erase & at
  cout << "v[7] = " << v.at(7) << endl;

  v.erase(7);
  cout << "after erase v[7] = " << v.at(7) << endl;
  cout << v << endl << endl;

  // test insert
  v.insert(7, 42);
  cout << "after insert v[7] = " << v.at(7) << endl;
  cout << v << endl << endl;

  // test exceptions
  try {
    cout << "try to get v.at(100)" << endl;
    cout << v.at(100) << endl;
  } catch (const std::out_of_range& e) {
    cout << "Exception: " << e.what() << endl;
  }

  cout << endl;

  try {
    cout << "try to v.insert(100, 5)" << endl;
    v.insert(100, 5);
  } catch (const std::out_of_range& e) {
    cout << "Exception: " << e.what() << endl;
  }

  cout << endl;

  try {
    cout << "try to v.erase(100)" << endl;
    v.erase(100);
  } catch (const std::out_of_range& e) {
    cout << "Exception: " << e.what() << endl;
  }

  // test dop (+ and -)

  Vector<int> BIBA(1, 0);
  Vector<int> BOBA(1, 0);

  for (int i = 0; i < 10; i++) {
    BIBA.push_back(i);
    BOBA.push_back(9 - i);
  }

  cout << BIBA << endl << BOBA << endl;

  Vector<int> ABOBA = BIBA + BOBA;
  cout << ABOBA << endl;

  Vector<int> AMOGUS = BIBA - BOBA;
  cout << AMOGUS << endl;
}
