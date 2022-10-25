#pragma once

#include <iostream>
#include <string>

using namespace std;

class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0);
  friend ostream &operator<<(ostream &out, Point &p);
};

class Shape {
 protected:
  Point pos;
  unsigned long id;

 public:
  Shape(Point pos = {0});
  virtual void print();
  unsigned long get_id();
  unsigned long next_id();
  virtual double get_contour_length();
  bool operator==(Shape &s);
};

class Circle : public Shape {
 protected:
  double r;
  string text;

 public:
  Circle(Point pos = {0}, double r = 0, string text = "");
  virtual void print();
  virtual double get_contour_length();
};

class Segment : public Shape {
 protected:
  Point start, end;

 public:
  Segment(Point start = {0}, Point end = {0});
  virtual void print();
  virtual double get_contour_length();
};