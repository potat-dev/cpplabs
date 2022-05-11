// Создайте класс Time с конструкторами
// Time(), Time(int hour), Time(int hour, int min),
// Time(int h, int m, int s) и Time(char *time)

#include "time.h"

using namespace std;

int main() {
  Time test0(6, 18);
  test0.print();

  Time test1("6:18:01");
  test1.print();
  
  Time test2("16:18");
  test2.print();

  test2 = test1;
  test2.print();

  Time test3(test0);
  test3.print();
}