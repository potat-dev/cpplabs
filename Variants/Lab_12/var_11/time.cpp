#include "time.h"

Time::Time(int hour, int minute, int second):
  _hour(hour), _minute(minute), _second(second) {
}

Time::Time(const char *time):
  _hour(0), _minute(0), _second(0) {
  sscanf(time, "%d:%d:%d", &_hour, &_minute, &_second);
}
    
// сеттеры

void Time::set_hour(int h) {
  _hour = h % 24;
}

void Time::set_minute(int m) {
  _minute = m % 60;
}

void Time::set_second(int s) {
  _second = s % 60;
}

// геттеры

int Time::get_hour() {
  return _hour;
}

int Time::get_minute() {
  return _minute;
}

int Time::get_second() {
  return _second;
}

// вывод на экран

void Time::print() {
  printf("%02d:%02d:%02d\n", _hour, _minute, _second);
}