#include "shape.h"
#include "list.h"

using namespace std;

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
      size--;
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