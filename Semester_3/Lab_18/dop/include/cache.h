// Реализовать LFU кэш фиксированного размера (количество записей задается в
// конструкторе) для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются
// записи, которые запрашивались реже всего. Удобной реализацией такого кэша
// является map<адрес, число запросов адреса>. При реализации использовать
// дополнительный multimap или priority_queue (т.е. всего 2 map) для быстрого
// поиска адреса, который встречался наименьшее число раз.

// Если же все элементы в кэше имеют одинаковый счётчик, то в этом случае
// вытеснение осуществляется по методу FIFO: первым вошёл - первым вышел
// https://bimlibik.github.io/posts/cache-algorithms/#least-frequently-used---lfu-наименее-часто-используемый

// методы:
// LfuCache(size_t size)
// bool find_and_add(const string &address); // возвращает true, если адрес
// найден в кэше operator<< - для вывода на экран

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class LfuCache {
 private:
  // {key, {value, count}}
  std::map<std::string, std::pair<std::string, size_t>> cache;
  std::multimap<size_t, std::string> freq;
  size_t size;

 public:
  LfuCache(size_t size);
  std::string get(const std::string &str);
  void add(const std::string &address, const std::string &value);
  friend std::ostream &operator<<(std::ostream &out, const LfuCache &cache);
  void print();
};