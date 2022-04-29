#pragma once

#include <stdio.h>

using namespace std;

class Time {
  private:
    int _hour, _minute, _second;

  public:
    // конструкторы

    Time(int hour = 0, int minute = 0, int second = 0);
    Time(const char *time);
    
    // сеттеры

    void set_hour(int h);
    void set_minute(int m);
    void set_second(int s);

    // геттеры

    int get_hour();
    int get_minute();
    int get_second();

    // вывод на экран

    void print();
};