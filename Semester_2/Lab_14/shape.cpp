#include "shape.h"

using namespace std;

// class Point

Point::Point(int x, int y):
  _x(x), _y(y) {
}

const int Point::x() {
  return _x;
}

const int Point::y() {
  return _y;
}

// class Shape

Shape::Shape(int id, int x, int y):
  id(id), x(x), y(y) {
}

void Shape::print() {
  cout << id << ", " << x << ", " << y << endl;
}

// class Circle

Circle::Circle(int id, int x, int y, int r, string text):
  Shape(id, x, y), r(r), text(text) {
}

void Circle::print() {
  cout << id << ", " << x << ", " << y << endl;
}

// class Segment

Segment::Segment(int id, int x_start, int y_start, int x_end, int y_end):
  Shape(id, x_start, y_start),
  x_start(x_start), y_start(y_start),
  x_end(x_end), y_end(y_end) {
}

void Segment::print() {
  cout << "id: " << id
       << ", x: " << x
       << ", y: " << y << endl;
  cout << "x_start: " << x_start
       << ", y_start: " << y_start
       << ", x_end: " << x_end
       << ", y_end: " << y_end << endl;
}

// class FigureList

FigureList::FigureList() {
  head = NULL;
  size = 0;
}

void FigureList::push_front(Shape* s) {

}

Shape& FigureList::get(int id) {

}

void FigureList::erase(int id) {

}

void FigureList::printAll() {

}