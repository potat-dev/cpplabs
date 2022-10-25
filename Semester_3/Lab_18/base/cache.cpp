#include "cache.h"

using namespace std;

LfuCache::LfuCache(size_t size) : size(size) {}

bool LfuCache::find_and_add(const std::string &address) {
  auto it = cache.find(address);
  if (it != cache.end()) {
    freq.erase(freq.find(it->second));
    freq.insert({++it->second, address});
    return true;
  } else {
    if (cache.size() == size) {
      auto it2 = freq.begin();
      cache.erase(it2->second);
      freq.erase(it2);
    }
    cache.insert({address, 1});
    freq.insert({1, address});
    return false;
  }
}

std::ostream &operator<<(std::ostream &out, const LfuCache &cache) {
  for (auto it = cache.freq.begin(); it != cache.freq.end(); ++it) {
    out << it->second << " - " << it->first
        << (it == --cache.freq.end() ? "" : ", ");
  }
  return out;
}