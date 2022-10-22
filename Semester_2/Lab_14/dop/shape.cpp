#include "shape.h"

#include "math.h"

#define M_2PI 6.283185307179586232

using namespace std;

// class Point

Point::Point(double x, double y) : x(x), y(y) {}

ostream &operator<<(ostream &out, Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

// class Shape

Shape::Shape(Point pos) : id(next_id()), pos(pos) {}

unsigned long Shape::next_id() {
  static unsigned long next_id = 0;
  return next_id++;
}

void Shape::print() {
  cout << "id: " << id << endl;
  cout << "pos: " << pos << endl;
}

unsigned long Shape::get_id() { return id; }

double Shape::get_contour_length() { return 0; }

bool Shape::operator==(Shape &s) {
  return get_contour_length() == s.get_contour_length();
}

// class Circle

Circle::Circle(Point pos, double r, string text)
    : Shape(pos), r(r), text(text) {}

void Circle::print() {
  cout << "type: Circle" << endl;
  Shape::print();
  cout << "radius: " << r << endl;
  cout << "text: " << text << endl;
}

double Circle::get_contour_length() { return M_2PI * r; }

// class Segment

Segment::Segment(Point start, Point end)
    : Shape(start), start(start), end(end) {}

void Segment::print() {
  cout << "type: Segment" << endl;
  Shape::print();
  cout << "start pos: " << start << endl;
  cout << "end pos: " << end << endl;
}

double Segment::get_contour_length() {
  return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}