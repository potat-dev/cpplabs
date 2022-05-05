#include "shape.h"

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

Shape::Shape(int id, int x, int y):
  id(id), x(x), y(y) {
}

void Shape::print() {
  cout << "id: " << id << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
}

int Shape::get_id() {
  return id;
}

// class Circle

Circle::Circle(int id, int x, int y, int r, string text):
  Shape(id, x, y), r(r), text(text) {
}

void Circle::print() {
  cout << "type: Circle" << endl;
  Shape::print();
  cout << "r: " << r << endl;
  cout << "text: " << text << endl;
}

// class Segment

Segment::Segment(int id, int x_start, int y_start, int x_end, int y_end):
  Shape(id, x_start, y_start),
  x_start(x_start), y_start(y_start),
  x_end(x_end), y_end(y_end) {
}

void Segment::print() {
  cout << "type: Segment" << endl;
  Shape::print();
  cout << "start x: " << x_start << endl
       << "start y: " << y_start << endl;
  cout << "end x: " << x_end << endl
       << "end y: " << y_end << endl;
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