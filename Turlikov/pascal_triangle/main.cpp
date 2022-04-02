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

int n = 67; // 67 максимум
// так как 14226520737620288370 (число посередине)
// в двоичном виде: 1100010101101110110000010011110001001011100101011110001101110010
// ровно 64 бита - uint64

int main() {
  vector <uint64_t> prev;
  vector <uint64_t> now {1};

  for (int i = 0; i < n; i++) {
    prev = now;
    now.resize(now.size() + 1);

    // заполняем новую строку треугольника
    for (int x = 0; x < now.size(); x++)
      now[x] = get(prev, x-1) + get(prev, x);
  }

  cout << "line " << n << ":\n";
  print(now);
}