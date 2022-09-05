// Реализовать LFU кэш фиксированного размера (количество записей задается в конструкторе)
// для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются записи, которые запрашивались реже всего.
// Удобной реализацией такого кэша является map<адрес, число запросов адреса>.
// При реализации использовать дополнительный multimap или priority_queue (т.е. всего 2 map)
// для быстрого поиска адреса, который встречался наименьшее число раз.

// методы:
// LfuCache(size_t size)
// bool find_and_add(const std::string &address); // возвращает true, если адрес найден в кэше
// operator<< - для вывода на экран


#include <iostream>
#include <map>
#include <string>
#include <vector>

class LfuCache {
  private:
    std::map<std::string, size_t> cache;
    std::multimap<size_t, std::string> cache2;
    size_t size;

  public:
    LfuCache(size_t size) : size(size) {}

    bool find_and_add(const std::string &address) {
        auto it = cache.find(address);
        if (it != cache.end()) {
            cache2.erase(cache2.find(it->second));
            cache2.insert({++it->second, address});
            return true;
        } else {
            if (cache.size() == size) {
                auto it2 = cache2.begin();
                cache.erase(it2->second);
                cache2.erase(it2);
            }
            cache.insert({address, 1});
            cache2.insert({1, address});
            return false;
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const LfuCache &cache) {
        for (auto it = cache.cache2.begin(); it != cache.cache2.end(); ++it) {
            out << it->second << " - " << it->first << " ";
        }
        return out;
    }
};