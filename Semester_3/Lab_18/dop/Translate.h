// Реализовать LFU кэш фиксированного размера (количество записей задается в
// конструкторе) для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются
// записи, которые запрашивались реже всего. Удобной реализацией такого кэша
// является map<адрес, число запросов адреса>. При реализации использовать
// дополнительный multimap или priority_queue (т.е. всего 2 map) для быстрого
// поиска адреса, который встречался наименьшее число раз.

// написать тестирующую программу

// доп: линкед лист со всеми словами для перевода,
// текст переводится с помощью этих слов, слово сначала ищем в кеше а потом

// алгоритм:
// 1. считываем словарь
// - сохраняем в линкед лист в виде пар слово-перевод
// - (поиск по линкед листу долгий)
// 2. считываем текст
// - считываем пословно, сразу переводя
// 3. перевод текста
// - ищем слово в кеше
// - если находим, то берем перевод из кеша и увеличиваем счетчик
// - если не находим, то ищем в линкед листе
// - если находим, то берем перевод и добавляем в кеш
// - если не находим, то выводим null

#pragma once

#include <fstream>
#include <list>
#include <nlohmann/json.hpp>
#include <string>

#include "cache.h"

using namespace std;

class Translate {
 private:
  LfuCache cache;
  list<pair<string, string>> words;

 public:
  // constructor from ison file with words and translations
  Translate(const string& filename, int cache_size = 16) : cache(cache_size) {
    ifstream file(filename);
    nlohmann::json j;
    file >> j;

    for (auto& [key, value] : j.items()) {
      words.push_back({key, value});
    }
  }

  // translate word
  string translate(const string& word) {
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

  // print cache
  void print_cache() { cache.print(); }

  // print words
  void print_words() {
    for (auto& pair : words) {
      cout << pair.first << " - " << pair.second << endl;
    }
  }
};