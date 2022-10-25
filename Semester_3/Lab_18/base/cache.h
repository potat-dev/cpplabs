// Реализовать LFU кэш фиксированного размера (количество записей задается в
// конструкторе) для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются
// записи, которые запрашивались реже всего. Удобной реализацией такого кэша
// является map<адрес, число запросов адреса>. При реализации использовать
// дополнительный multimap или priority_queue (т.е. всего 2 map) для быстрого
// поиска адреса, который встречался наименьшее число раз.

// методы:
// LfuCache(size_t size)
// bool find_and_add(const std::string &address); // возвращает true, если адрес
// найден в кэше operator<< - для вывода на экран

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class LfuCache {
 private:
  std::map<std::string, size_t> cache;
  std::multimap<size_t, std::string> freq;
  size_t size;

 public:
  LfuCache(size_t size);
  bool find_and_add(const std::string &address);
  friend std::ostream &operator<<(std::ostream &out, const LfuCache &cache);
};