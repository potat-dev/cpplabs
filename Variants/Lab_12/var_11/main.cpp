// Создайте класс Time с конструкторами
// Time(), Time(int hour), Time(int hour, int min),
// Time(int h, int m, int s) и Time(char *time)

//! Спросить у Линского, нужно ли перегружать операторы?

// Используйте приватные поля для данных
// Реализуйте конструктор, который должен устанавливать значения по умолчанию
// Реализуйте методы для чтения и записи значений полей (set, get)
// Реализуйте операторы ввода и вывода (перегрузка operator<< и operator>> не требуется)
// Если требуется, напишите конструктор копий, оператор присваивания и деструктор 
// Напишите программу для тестирования вашего класса

// TODO:
// добавить проверку на корректность данных

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Time {
  private:
    int _hour, _minute, _second;

  public:
    // конструкторы

    Time(int hour = 0, int minute = 0, int second = 0):
      _hour(hour), _minute(minute), _second(second) {
      printf("%d : %d : %d\n", _hour, _minute, _second); //? test
    }

    Time(const char *time):
      _hour(0), _minute(0), _second(0) {
      sscanf(time, "%d:%d:%d", &_hour, &_minute, &_second);
      printf("%02d:%02d:%02d\n", _hour, _minute, _second); //? test
    }
    
    // сеттеры

    void set_hour(int h) {
      _hour = h % 24;
    }

    void set_minute(int m) {
      _minute = m % 60;
    }

    void set_second(int s) {
      _second = s % 60;
    }

    // геттеры

    int get_hour() {
      return _hour;
    }

    int get_minute() {
      return _minute;
    }

    int get_second() {
      return _second;
    }

    // вывод на экран

    void print() {
      printf("%02d:%02d:%02d", _hour, _minute, _second);
    }
};

int main() {
  Time test0(6, 18);
  Time test1("6:18:01");
  Time test2("16:18");
}