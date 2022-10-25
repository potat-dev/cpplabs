#include <iostream>
#include <string>

using namespace std;

string operator*(string str, int count) {
  // теперь можно умножать строки :)
  string temp;
  for (int i = 0; i < count; i++)
    temp += str;
  return temp;
}

int main() {
  string str;
  cin >> str;
  cout << str * 50; // прям как в python
}