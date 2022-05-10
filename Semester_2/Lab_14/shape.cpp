#include "shape.h"

#include "math.h"
#define PI 3.1415926535898

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
  return 2 * PI * r;
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

// class Node

Node::Node(Shape* s, Node* next):
  shape(s), next(next) {
}

// class FigureList

FigureList::FigureList() {
  head = NULL;
  size = 0;
}

void FigureList::push_front(Shape* s) {
  Node *temp = new Node(s);
  if (size) {
    temp->next = head;
    head = temp;
  } else {
    head = temp;
  }
  size++;
}

void FigureList::push_back(Shape* s) {
  Node *temp = new Node(s);
  if (size) {
    Node *last = head;
    while (last->next)
      last = last->next;
    last->next = temp;
  } else {
    head = temp;
  }
  size++;
}

Shape& FigureList::get(int id) {
  Node *curr = head;
  while (curr) {
    if (curr->shape->get_id() == id)
      return *(curr->shape);
    curr = curr->next;
  }
  return *(curr->shape);
}

void FigureList::erase(int id) {
  Node *curr = head, *prev = NULL;
  while (curr) {
    if (curr->shape->get_id() == id) {
      if (curr == head) { // первый элемент
        head = head->next;
      } else if (curr->next) { // элемент посередине
        prev->next = curr->next;
      } else { // последний элемент
        prev->next = NULL;
      }
      delete curr->shape;
      delete curr;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

void FigureList::print_all() {
  Node* curr = head;
  int i = 1;
  while (curr) {
    cout << "\nitem: " << i++ << endl;
    curr->shape->print();
    curr = curr->next;
  }
}