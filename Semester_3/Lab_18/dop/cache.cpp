#include "cache.h"

using namespace std;

LfuCache::LfuCache(size_t size) : size(size) {}

string LfuCache::get(const string &str) {
  // if str is in cache, return value
  // else return empty string
  // if str is in cache, increase count
  auto it = cache.find(str);
  if (it != cache.end()) {
    auto it2 = freq.find(it->second.second);
    while (it2->second != str) it2++;  // search for str in freq
    freq.erase(it2);
    freq.insert({++it->second.second, str});
    return it->second.first;
  }
  return "";
}

void LfuCache::add(const string &address, const string &value) {
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

ostream &operator<<(ostream &out, const LfuCache &cache) {
  cout << "Freq:" << endl;
  for (auto it = cache.freq.begin(); it != cache.freq.end(); ++it) {
    out << it->second << " - " << it->first << " " << endl;
  }
  return out;
}

void LfuCache::print() { cout << *this << endl; }