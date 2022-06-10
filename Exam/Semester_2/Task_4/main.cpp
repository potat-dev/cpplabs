#include <stdlib.h>
#include <iostream>
using namespace std;

class node_t {
  private:
    int value;
    node_t* next;
  public:
    node_t(int v = 0);
    node_t* get_next();
    int get_value();
    void set_next(node_t *n);
};

node_t::node_t(int v) {
  value = v;
  next = NULL;
}

node_t* node_t::get_next() {
  return next;
}

int node_t::get_value() {
  return value;
}

void node_t::set_next(node_t *n) {
  this->next = n;
}

class list_t {
  private:
    node_t *head;
    size_t size;
  public:
    list_t();
    list_t(list_t& l);
    ~list_t();

    list_t& push_back(int value);
    list_t& set(int index, int value);
    void print();
};

list_t::list_t() {
  head = NULL;
  size = 0;
}

list_t::list_t(list_t& l) {
  head = NULL;
  node_t *last = NULL;
  for (node_t *lcurr = l.head; lcurr != NULL; lcurr = lcurr->get_next()) {
    node_t *curr = new node_t(lcurr->get_value());
    if (head == NULL) {
      head = curr;
    } else {
      last->set_next(curr);
    }
    last = curr;
  }
  size = l.size;
}

list_t::~list_t() {
  node_t *curr = head;
  while (curr != NULL) {
    node_t *next = curr->get_next();
    delete curr;
    curr = next;
  }
  size = 0; head = NULL;
}

list_t& list_t::push_back(int value) {
  node_t *n = new node_t(value);
  if (head == NULL) {
    head = n;
  } else {
    node_t *curr = head;
    while (curr->get_next() != NULL) {
      curr = curr->get_next();
    }
    curr->set_next(n);
  }
  return *this;
}

list_t& list_t::set(int index, int value) {
  node_t *curr = head;
  for (int id = 0; id != index; id++) {
    curr = curr->get_next();
  }
  
  return *this;
}

void list_t::print() {
  for (node_t *curr = head; curr != NULL; curr = curr->get_next()) {
    cout << curr->get_value() << " ";
  }
  cout << endl;
}


int main() {
  list_t l;
  l.push_back(1).push_back(2).push_back(42).push_back(618).print();

  list_t l2(l);
  l2.push_back(0);
  l2.print();
  l.print();
}