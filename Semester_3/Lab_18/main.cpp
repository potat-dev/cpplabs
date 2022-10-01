// Реализовать LFU кэш фиксированного размера (количество записей задается в
// конструкторе) для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются
// записи, которые запрашивались реже всего. Удобной реализацией такого кэша
// является map<адрес, число запросов адреса>. При реализации использовать
// дополнительный multimap или priority_queue (т.е. всего 2 map) для быстрого
// поиска адреса, который встречался наименьшее число раз.

// написать тестирующую программу

#include <iostream>
#include <string>

#include "LFU_cache.h"

using namespace std;

int main() {
  LfuCache cache(3);

  cout << "Try found AFFB: "
       << (cache.find_and_add("AFFB") ? "found" : "not found") << endl
       << "Cache: " << cache << endl;
  cout << "Try found AFFB: "
       << (cache.find_and_add("AFFB") ? "found" : "not found") << endl
       << "Cache: " << cache << endl;
  cout << "Try found AFF: "
       << (cache.find_and_add("AFF") ? "found" : "not found") << endl
       << "Cache: " << cache << endl;
  cout << "Try found AFB: "
       << (cache.find_and_add("AFB") ? "found" : "not found") << endl
       << "Cache: " << cache << endl;
  cout << "Try found AFB123: "
       << (cache.find_and_add("AFB123") ? "found" : "not found") << endl
       << "Cache: " << cache << endl;
}
