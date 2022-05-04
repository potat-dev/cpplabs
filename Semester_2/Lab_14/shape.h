#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Point {
  private:
    int _x, _y;

  public:
    Point(int x = 0, int y = 0);
    const int x();
    const int y();
};

class Shape {
  protected:
    int id;
    int x, y;

  public:
    Shape(int id = 0, int x = 0, int y = 0);
    virtual void print();
};

class Circle : public Shape {
  protected:
    int r;
    string text;

  public:
    Circle(int id, int x, int y, int r, string text);
    virtual void print();
};

class Segment : public Shape {
  protected:
    int x_start, y_start, x_end, y_end;
  
  public:
    Segment(int id, int x_start, int y_start, int x_end, int y_end);
    virtual void print();
};

class FigureList {
  private:
    Shape* head;
    int size;

  public:
    FigureList();

    // добавить фигуру в начало списка
    void push_front(Shape* s);

    // найти фигуру всписке по идентификатору
    Shape &get(int id);
    
    // удалить фигуру из списка
    void erase(int id);
  
    // вывести на экран в текстовом режиме информацию о всех фигурах в списке
    void printAll();
};