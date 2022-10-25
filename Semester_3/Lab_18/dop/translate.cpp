#include "translate.h"

using namespace std;

Translate::Translate(const string& filename, int cache_size = 16)
    : cache(cache_size) {
  ifstream file(filename);
  nlohmann::json j;
  file >> j;

  for (auto& [key, value] : j.items()) {
    words.push_back({key, value});
  }
}

string Translate::translate(const string& word) {
  string translation = cache.get(word);
  if (translation != "") {
    return translation;
  }

  for (auto& pair : words) {
    if (pair.first == word) {
      cache.add(word, pair.second);
      return pair.second;
    }
  }

  return "<>";
}

void Translate::print_cache() { cache.print(); }

void Translate::print_words() {
  for (auto& pair : words) {
    cout << pair.first << " - " << pair.second << endl;
  }
}