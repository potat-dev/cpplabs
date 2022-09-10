// Реализовать LFU кэш фиксированного размера (количество записей задается в конструкторе)
// для адресов (адресом является строка, например, “AFFB”).
// Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются записи, которые запрашивались реже всего.
// Удобной реализацией такого кэша является map<адрес, число запросов адреса>.
// При реализации использовать дополнительный multimap или priority_queue (т.е. всего 2 map)
// для быстрого поиска адреса, который встречался наименьшее число раз.

// написать тестирующую программу

// доп: линкед лист со всеми словами для перевода,
// текст переводится с помощью этих слов, слово сначала ищем в кеше а потом 

#include "Translate.h"
#include <iostream>
#include <fstream>
#include <string>

#define CACHE_SIZE 10

using namespace std;

int main() {
    ifstream fin("input.txt");
    string word;
    Translate Trans("words.json", CACHE_SIZE);
    Trans.print_words();
    cout << endl << "Start translation:" << endl;
    while (fin >> word) {
      cout << Trans.translate(word) << endl;
    }
    cout << endl;
    Trans.print_cache();
    return 0;
}
