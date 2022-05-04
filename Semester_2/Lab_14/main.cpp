// Программа должна хранить схему в виде заданной в задании
// структуры данных, где хранятся геометрические фигуры.
// Каждая фигура характеризуется уникальным идентификатором
// (int) id, координатами на экране (x, y), а также своими параметрами

// Программа должна уметь работать с фигурами, указанными в задании.
// Каждая фигуру должна уметь выводить на экран свои параметры
// в текстовом режиме с помощью метода print().
// Возможно, в будущем будут добавлены новые фигуры

// Класс FigureList должен быть основан на связном списке.
// Связаный список должен быть реализован с помощью двух классов
// Node (элемент списка) и List (сам список)

// TODO:
// связный список (List) элементов (Node)
// вывод параметров фигуры через метод print()
// Circle: радиус, надпись произвольной длины
// Segment: координаты начала и коодинаты конца

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Point {
  public:
    int x, y;

    Point(int x = 0, int y = 0):
      x(x), y(y) {
    };
};

class Shape {
  protected:
    int id;
    int x, y;

  public:
    Shape(int id = 0, int x = 0, int y = 0):
      id(id), x(x), y(y) {
    }

    virtual void print() {
      cout << id << ", " << x << ", " << y << endl;
    }
};

class Circle : public Shape {
  protected:
    int r;
    string text;

  public:
    Circle(int id, int x, int y, int r, string text):
      Shape(id, x, y), r(r), text(text) {
    }
    
    virtual void print() {
      cout << id << ", " << x << ", " << y << endl;
    }
};

class Segment : public Shape {
  protected:
    int x_start, y_start;
    int x_end, y_end;
  
  public:
    Segment(int id, int x_start, int y_start, int x_end, int y_end):
      Shape(id, x_start, y_start),
      x_start(x_start), y_start(y_start),
      x_end(x_end), y_end(y_end) {
    }

    virtual void print() {
      cout << "id: " << id
           << ", x: " << x
           << ", y: " << y << endl;
      cout << "x_start: " << x_start
           << ", y_start: " << y_start
           << ", x_end: " << x_end
           << ", y_end: " << y_end << endl;
    }
};

class FigureList {
  private:
    Shape* arr[100];
    int size = 0;

  public:
    void add(Shape* s) {
      // if (size) arr[size-1]->print();
      arr[size++] = s;
    }

    Shape &get(int id) {
      return *arr[id];
    }
  
    // найти фигуру всписке по идентификатору
    Shape& findFigure(int id) {
      return *arr[id];
    }
    
    // удалить фигуру из списка
    void erase(int id) {
      
    }
  
    // вывести на экран в текстовом режиме информацию о всех фигурах в списке
    void printAll();
};


int main() {
  FigureList list;

  Circle *c1 = new Circle(42, 0, 0, 1, "hello");
  cout << "c1->print(): ";
  c1->print();

  Circle *c2 = new Circle(24, 6, 1, 8, "hello2");
  Segment *s1 = new Segment(1, 0, 0, 42, 42);

  list.add(c1);
  list.add(c2);
  list.add(s1);

  cout << "list.get(2).print(): ";
  list.get(2).print();
}