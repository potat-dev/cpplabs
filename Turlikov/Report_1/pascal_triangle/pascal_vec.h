#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;

uint64_t get(vector<uint64_t> &vec, uint16_t i) {
  if (i < 0 || i >= vec.size()) return 0;
  else return vec[i];
}

void print(vector<uint64_t> &vec) {
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << endl;
}

void print_line(uint16_t line) {
  vector <uint64_t> prev;
  vector <uint64_t> now {1};

  for (int i = 0; i < line; i++) {
    prev = now;
    now.resize(now.size() + 1);

    // заполняем новую строку треугольника
    for (int x = 0; x < now.size(); x++)
      now[x] = get(prev, x-1) + get(prev, x);
  }

  print(now);
}