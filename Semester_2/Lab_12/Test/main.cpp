#include <iostream>
#include <string>
#include "snippets.h"

using namespace std;

int main() {
  string hello = "hello";
  int arr[5] = {3, 4, 5, 6, 7};

  Test test_1 {{1, 2, 3, 4, 5}, 4242};
  Test test_2;

  test_1.print();
  test_2.print();
  test_2.arr[0] = 42;

  HugeInt h;
  cout << h.str << endl;
  h.set(arr);
  h.print();
}