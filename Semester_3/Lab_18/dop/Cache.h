// Реализовать LFU кэш фиксированного размера (количество записей задается в конструкторе)
// для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются записи, которые запрашивались реже всего.
// Удобной реализацией такого кэша является map<адрес, число запросов адреса>.
// При реализации использовать дополнительный multimap или priority_queue (т.е. всего 2 map)
// для быстрого поиска адреса, который встречался наименьшее число раз.

// Если же все элементы в кэше имеют одинаковый счётчик,
// то в этом случае вытеснение осуществляется по методу FIFO: первым вошёл - первым вышел
// -> https://bimlibik.github.io/posts/cache-algorithms/#least-frequently-used---lfu-наименее-часто-используемый

// методы:
// LfuCache(size_t size)
// bool find_and_add(const string &address); // возвращает true, если адрес найден в кэше
// operator<< - для вывода на экран


#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class LfuCache {
  private:
    map<string, pair<string, size_t>> cache; // {key, {value, count}}
    multimap<size_t, string> freq;
    size_t size;

  public:
    LfuCache(size_t size) : size(size) {}

/*
    bool find_and_add(const string &address, const string &value) {
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
*/

    string get(const string &address) {
        // if address is in cache, return value
        // else return empty string
        // if address is in cache, increase count
        auto it = cache.find(address);
        if (it != cache.end()) {
            freq.erase(freq.find(it->second.second));
            freq.insert({++it->second.second, address});
            return it->second.first;
        } else {
            return "";
        }
    }

    void add(const string &address, const string &value) {
        // add address to cache
        // if cache is full, delete least frequently used address
        if (cache.size() == size) {
            auto it2 = freq.begin();
            cache.erase(it2->second);
            freq.erase(it2);
        }
        cache.insert({address, {value, 1}});
        freq.insert({1, address});
    }

    friend ostream &operator<<(ostream &out, const LfuCache &cache) {
        cout << "Freq: ";
        for (auto it = cache.freq.begin(); it != cache.freq.end(); ++it) {
            out << it->second << " - " << it->first << " ";
        }
        cout << endl << "Map: ";
        for (auto it = cache.cache.begin(); it != cache.cache.end(); ++it) {
            out << it->first << " - " << it->second.first << " (" << it->second.second << ") ";
        }
        return out;
    }

    // print
    void print() {
        cout << *this << endl;
    }
};