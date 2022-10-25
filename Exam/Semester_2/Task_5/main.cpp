// class Figure {
//   private:
//     int x, y;
// };

// class Rect : public Figure {
//   private:
//     int h, w;
// };

#include <iostream>
using namespace std;

class Date {
  private:
    int y, m, d;
  
  public:
    friend ostream& operator<<(std::ostream& out, const Date& d) {
      out << d.y << "." << d.m << "." << d.d;
      return out;
    }
};
