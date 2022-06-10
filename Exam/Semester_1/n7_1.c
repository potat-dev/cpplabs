#include <stdio.h>

// глобальные переменные
int global_var = 42;
int x, y, z;

void sum() {
  static int static_var; // доступен только в этой функции
  static_var = 777;
  // не сбрасывает значение при повторном заходе в функцию
  x = y + z;
  // здесь доступны переменные x, y, z, global_var
  // но не доступна переменная main_var (она локальная)
  
  // printf("%d", main_var); - ошибка
  // потому что это локальная переменная в другой функции
}

void main() {
  int main_var = 618;
  x = 6;
  y = 1;
  z = 8;
  sum();
  printf("%d %d %d ", x, y, z);
  printf("%d %d ", global_var, main_var);

  // printf("%d", static_var);
  // ошибка потому что это локальная переменная в другой функции
}