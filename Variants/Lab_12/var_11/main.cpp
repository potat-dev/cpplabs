// Создайте класс Time с конструкторами
// Time(), Time(int hour), Time(int hour, int min),
// Time(int h, int m, int s) и Time(char *time)

#include <stdio.h>
#include <stdlib.h>

class Time {
  private:
    int _hour, _minute, _second;

  public:
    Time(int hour = 0, int minute = 0, int second = 0):
      _hour(hour), _minute(minute), _second(second) {
      printf("%d : %d : %d\n", _hour, _minute, _second); //? test
    }

    Time(const char *time):
      _hour(0), _minute(0), _second(0) {
      sscanf(time, "%d:%d:%d", &_hour, &_minute, &_second);
      printf("%d : %d : %d\n", _hour, _minute, _second); //? test
    }
};

int main() {
  Time test0(6, 18);
  Time test1("16:18:01");
  Time test2("16:18");
}