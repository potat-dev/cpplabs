#include <stdio.h>

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// задача о черепашке

// смысл задачи: есть черепашка, которая может двигаться вправо или вниз
// на каждом шаге она может выбрать один из двух вариантов движения
// в начале она стоит в левом верхнем углу
// в конце она должна дойти до правого нижнего угла
// в каждой клетке поля записано число, которое нужно прибавить к сумме
// черепашка должна выбрать такой путь, чтобы сумма чисел в клетках была
// максимальной

int main() {
  int x_size, y_size, x, y;
  int i, j;  // счетчики
  // x_size - количество столбцов, y_size - количество строк
  vector<vector<int>> table;
  vector<vector<int>> down;
  // массив, в котором записаны числа, которые нужно
  // прибавить к сумме, если черепашка движется вверх
  vector<vector<int>> right;
  // массив, в котором записаны числа, которые нужно прибавить к сумме, если
  // черепашка движется вправо

  cout << "y_size = ";
  cin >> y_size;
  cout << "x_size = ";
  cin >> x_size;

  table.resize(y_size + 1);
  for (i = 0; i < y_size + 1; i++) {  // проход по строкам
    table[i].resize(x_size + 1);
  }

  ifstream fin("turtle_up.txt");
  down.resize(y_size);
  for (i = 0; i < y_size; i++) {  // проход по строкам
    down[i].resize(x_size + 1);
    for (j = 0; j < x_size + 1; j++) {  // проход по столбцам
      fin >> down[i][j];
    }
  }
  fin.close();

  fin.open("turtle_right.txt");
  right.resize(y_size + 1);
  for (i = 0; i < y_size + 1; i++) {  // проход по строкам
    right[i].resize(x_size);
    for (j = 0; j < x_size; j++) {  // проход по столбцам
      fin >> right[i][j];
    }
  }
  fin.close();

  // заполняем таблицу
  // черепашка может двигаться вправо или вверх
  // кординатная сетка начинается с левого верхнего угла
  // в каждой клетке записано число, которое нужно прибавить к сумме
  // черепашка стоит в левом верхнем углу

  // заполняем первую строку
  table[0][0] = 0;
  for (j = 1; j < x_size + 1; j++) {
    table[0][j] = table[0][j - 1] + right[0][j - 1];
  }

  // заполняем первый столбец
  for (i = 1; i < y_size + 1; i++) {
    table[i][0] = table[i - 1][0] + down[i - 1][0];
  }

  // заполняем остальную часть таблицы
  for (i = 1; i < y_size + 1; i++) {
    for (j = 1; j < x_size + 1; j++) {
      table[i][j] = max(table[i - 1][j] + down[i - 1][j],
                        table[i][j - 1] + right[i][j - 1]);
    }
  }

  // выводим таблицу
  for (i = 0; i < y_size + 1; i++) {
    for (j = 0; j < x_size + 1; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }

  // выводим путь черепашки
  x = x_size;
  y = y_size;
  while (x != 0 || y != 0) {
    if (x == 0) {
      cout << "up" << endl;
      y--;
    } else if (y == 0) {
      cout << "right" << endl;
      x--;
    } else if (table[y - 1][x] + down[y - 1][x] >
               table[y][x - 1] + right[y][x - 1]) {
      cout << "up" << endl;
      y--;
    } else {
      cout << "right" << endl;
      x--;
    }
  }

  // выводим максимальную сумму
  cout << "max sum = " << table[y_size][x_size] << endl;
}

// Сложность алгоритма O(n*m), где n и m - размеры таблицы, что соответствует
// O(n^2)
