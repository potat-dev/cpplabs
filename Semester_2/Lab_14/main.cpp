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

#include <cstdlib>
#include <string>

using namespace std;

class Shape {
  protected:
    int id;
    int x, y;

  public:
    Shape(int id, int x, int y);
    void print();
};

class Circle : public Shape {
  protected:
    int r;
    string text;

  public:
    Circle(int id, int x, int y, int r, string text);
    void print();
};

class Segment : public Shape {
  protected:
    int x_start, y_start, x_end, y_end;
  
  public:
    Segment(int id, int x_start, int y_start, int x_end, int y_end);
    void print();
};

class FigureList {
  private:
    Shape* arr[100];
    int size = 0;

  public:
    void add(Shape* s);

    Shape &get(int id);

    // найти фигуру всписке по идентификатору
    Shape& findFigure(int id);

    // удалить фигуру из списка
    void erase(int id);

    // вывести на экран в текстовом режиме информацию о всех фигурах в списке
    void printAll();
};


int main() {
  FigureList list;
}