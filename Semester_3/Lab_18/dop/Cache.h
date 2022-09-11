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

    string get(const string &str) {
        // if str is in cache, return value
        // else return empty string
        // if str is in cache, increase count
        auto it = cache.find(str);
        if (it != cache.end()) {
            auto it2 = freq.find(it->second.second);
            while (it2->second != str) it2++; // search for str in freq
            freq.erase(it2);
            freq.insert({++it->second.second, str});
            return it->second.first;
        }
        return "";
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
        cout << "Freq:" << endl;
        for (auto it = cache.freq.begin(); it != cache.freq.end(); ++it) {
            out << it->second << " - " << it->first << " " << endl;
        }
        return out;
    }

    // print
    void print() {
        cout << *this << endl;
    }
};