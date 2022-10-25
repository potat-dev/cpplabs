#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	wcout << L"Русский текст" << endl;
  cout << "English " << L"text" << endl;
  // в обычный cout нельзя выводить wide-строки
}