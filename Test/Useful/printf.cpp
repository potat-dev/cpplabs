// https://www.delftstack.com/howto/cpp/how-to-print-a-string-in-cpp/#use-printf-function-to-print-a-string
// https://habr.com/ru/post/318962/

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "hello world";
  
  cout << s << endl;
  
  printf("%s\n", s.c_str());
}