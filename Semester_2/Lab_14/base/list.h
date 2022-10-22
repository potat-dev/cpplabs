#pragma once

#include "shape.h"

class Node {
 public:
  Shape* shape;
  Node* next;
  Node(Shape* s = NULL, Node* next = NULL);
};

class FigureList {
 private:
  Node* head;
  int size;

 public:
  FigureList();
  void push_front(Shape* s);
  void push_back(Shape* s);
  Shape& get(int id);
  void erase(int id);
  void print_all();
};