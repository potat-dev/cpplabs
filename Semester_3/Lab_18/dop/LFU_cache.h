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
    std::map<std::string, std::pair<std::string, size_t>> cache; // {key, {value, count}}
    std::multimap<size_t, std::string> freq;
    size_t size;

  public:
    LfuCache(size_t size) : size(size) {}

    bool find_and_add(const std::string &address, const std::string &value) {
        auto it = cache.find(address);
        if (it != cache.end()) {
            freq.erase(freq.find(it->second.second));
            freq.insert({++it->second.second, address});
            it->second.first = value; // update value
            return true;
        } else {
            if (cache.size() == size) {
                auto it2 = freq.begin();
                cache.erase(it2->second);
                freq.erase(it2);
            }
            cache.insert({address, {value, 1}});
            freq.insert({1, address});
            return false;
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const LfuCache &cache) {
        std::cout << "Freq: ";
        for (auto it = cache.freq.begin(); it != cache.freq.end(); ++it) {
            out << it->second << " - " << it->first << " ";
        }
        std::cout << std::endl << "Map: ";
        for (auto it = cache.cache.begin(); it != cache.cache.end(); ++it) {
            out << it->first << " - " << it->second.first << " (" << it->second.second << ") ";
        }
        return out;
    }
};