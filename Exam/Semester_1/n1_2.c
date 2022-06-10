#define test 42 // константа

#define sum(a, b) a + b // макрос

#define include_libs 1 // настройка

#ifdef include_libs // эту проверку выполняет препроцессор
  #include <stdio.h>
  #include <stdlib.h>
#endif

void main() {
  int a = 1;
  int b = 42;

  int x = sum(a, b);       // тут просто происходит замена на макрос sum
  int y = sum(a, b) * 2;   // a + b * 2
  int z = (sum(a, b)) * 2; // (a + b) * 2
  printf("%d %d %d", x, y, z);

}