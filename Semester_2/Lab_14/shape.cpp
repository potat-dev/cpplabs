#include "shape.h"
#include "math.h"
#define M_2PI 6.283185307179586232

using namespace std;

// class Point

Point::Point(int x, int y):
  x(x), y(y) {
}

ostream& operator<<(ostream &out, Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

// class Shape

Shape::Shape(int id, Point pos):
  id(id), pos(pos) {
}

void Shape::print() {
  cout << "id: " << id << endl;
  cout << "pos: " << pos << endl;
}

int Shape::get_id() {
  return id;
}

double Shape::get_contour_length() {
  return 0;
}

bool Shape::operator==(Shape &s) {
  return get_contour_length() == s.get_contour_length();
}

// class Circle

Circle::Circle(int id, Point pos, int r, string text):
  Shape(id, pos), r(r), text(text) {
}

void Circle::print() {
  cout << "type: Circle" << endl;
  Shape::print();
  cout << "radius: " << r << endl;
  cout << "text: " << text << endl;
}

double Circle::get_contour_length() {
  return M_2PI * r;
}

// class Segment

Segment::Segment(int id, Point start, Point end):
  Shape(id, start), start(start), end(end) {
}

void Segment::print() {
  cout << "type: Segment" << endl;
  Shape::print();
  cout << "start pos: " << start << endl;
  cout << "end pos: " << end << endl;
}

double Segment::get_contour_length() {
  return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}