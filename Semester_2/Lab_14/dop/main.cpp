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

// исправить: сделать чтобы айдишники задавались по умолчанию автоматически
// доп: написать функцию сравнения длин контуров(!) двух фигур
// (круг == отрезок -> длина окружности сравнивается с длиной отрезка)

#include "list.h"
#include "shape.h"

int main() {
  FigureList list;

  cout << endl << "---- id_2 id_1 id_0 -> [] ----" << endl;
  Circle *c1 = new Circle({0, 0}, 1, "lol kek");
  Circle *c2 = new Circle({4, 2}, 7, "cheburek");
  Segment *s1 = new Segment({0, 0}, {42, 42});

  list.push_front(c1);
  list.push_front(c2);
  list.push_front(s1);
  list.print_all();  // list now: [id_2, id_1, id_0]

  cout << endl << "---- id_4 -> [] <- id_3 ----" << endl;
  list.push_back(new Segment({6, 18}, {4, 2}));
  list.push_front(new Circle({7, 7}, 7, "kek"));
  list.print_all();  // list now: [id_4, id_2, id_1, id_0, id_3]

  cout << endl << "---- [] -> id_3 id_1 ----" << endl;
  cout << endl;
  list.get(3).print();
  cout << endl;
  list.get(1).print();

  cout << endl << "---- [] -x-> id_4 ----" << endl;
  list.erase(4);
  list.print_all();  // list now: [id_2, id_1, id_0, id_3]

  cout << endl << "---- [] -x-> id_0 ----" << endl;
  list.erase(0);
  list.print_all();  // list now: [id_2, id_1, id_3]

  cout << endl << "---- [] -x-> id_3 ----" << endl;
  list.erase(3);
  list.print_all();  // list now: [id_2, id_1]

  cout << endl << "---- id_5 -> [] ----" << endl;
  list.push_front(new Segment);
  list.print_all();  // list now: [id_5, id_2, id_1]

  cout << endl << "-------- dop --------" << endl;

  cout << endl << "contour id_1: " << list.get(1).get_contour_length();
  cout << endl << "contour id_2: " << list.get(2).get_contour_length();
  cout << endl << "contour id_5: " << list.get(5).get_contour_length();

  cout << endl << endl << "id_1 == id_2: ";
  cout << (list.get(1) == list.get(2) ? "True" : "False");

  cout << endl << "id_1 == id_5: ";
  cout << (list.get(1) == list.get(5) ? "True" : "False");

  cout << endl << "id_2 == id_5: ";
  cout << (list.get(2) == list.get(5) ? "True" : "False");

  // для теста нужно создать одинаковые Circle и Segment (например равные нулю)

  cout << endl << endl << "---- [] <- id_6 ----" << endl;
  list.push_back(new Circle);  // list now: [id_5, id_2, id_1, id_6]

  cout << endl << "contour id_6: " << list.get(6).get_contour_length();

  cout << endl << "id_5 == id_6: ";
  cout << (list.get(5) == list.get(6) ? "True" : "False") << endl;

  cout << endl << "------ list_2 ------" << endl;

  FigureList list2;
  for (double i = 0; i < 5; i++) {
    list2.push_front(new Circle({0, 0}, i));
    list2.push_back(new Segment({0, 0}, {i, i}));
  }

  list2.print_all();
  // list_2 now:
  // [id_15, id_13, id_11, id_9, id_7, id_8, id_10, id_12, id_14, id_16]
}