// Реализовать LFU кэш фиксированного размера (количество записей задается в конструкторе)
// для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются записи, которые запрашивались реже всего.
// Удобной реализацией такого кэша является map<адрес, число запросов адреса>.
// При реализации использовать дополнительный multimap или priority_queue (т.е. всего 2 map)
// для быстрого поиска адреса, который встречался наименьшее число раз.

// написать тестирующую программу

#include "LFU_cache.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  LfuCache cache(3);
  cout << cache.find_and_add("AFFB") << endl;
  cout << cache << endl;
  cout << cache.find_and_add("AFFB") << endl;
  cout << cache << endl;
  cout << cache.find_and_add("AFFB") << endl;
  cout << cache << endl;
  cout << cache.find_and_add("AFF") << endl;
  cout << cache << endl;
  cout << cache.find_and_add("AFB") << endl;
  cout << cache << endl;
  cout << cache.find_and_add("AFB123") << endl;
  cout << cache << endl;
}
