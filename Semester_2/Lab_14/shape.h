#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Point {
  public:
    int x, y;
    Point(int x = 0, int y = 0);
    friend ostream& operator<<(ostream &out, Point &p);
};

class Shape {
  protected:
    int id;
    Point pos;

  public:
    Shape(int id, Point pos = {0});
    virtual void print();
    int get_id();
    virtual double get_contour_length();
    bool operator==(Shape &s);
};

class Circle : public Shape {
  protected:
    int r;
    string text;

  public:
    Circle(int id, Point pos = {0}, int r = 1, string text = "");
    virtual void print();
    virtual double get_contour_length();
};

class Segment : public Shape {
  protected:
    Point start, end;
  
  public:
    Segment(int id, Point start = {0}, Point end = {0});
    virtual void print();
    virtual double get_contour_length();
};