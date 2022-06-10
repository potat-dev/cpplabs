void main() {
  // основные типы данных
  char a = -1;      // 1 байт
  short b = -2;     // 2 байта
  int c = -3;       // 4 байта
  long d = -4;      // 4 байта
  long long e = -5; // 8 байт

  unsigned char v = 6;       // 1 байт без знака
  unsigned short w = 7;      // 2 байта без знака
  unsigned int x = 8;        // 4 байта без знака
  unsigned long y = 9;       // 4 байта без знака
  unsigned long long z = 10; // 8 байт без знака

  float fl = 42.42;          // 4 байта
  double db = 4242.42424242; // 8 байт

  // приведение типов данных
  char some_char = 42;
  int some_int = (int) some_char;

  some_int = 1234567;
  some_char = (char) some_int; // число обрежется до 8 младших битов

  int n = 3;
  int m = 5;
  double some_double_1 = n / m; // будет 0 так как мы делим intы
  double some_double_2 = ((double) n) / m; // теперь мы doube делим на int = double
}