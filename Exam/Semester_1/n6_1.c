#include <stdio.h>

int global_var = 42; // глобальная переменная

int sum(int a, int b) {
  int s = a + b;
  return s;
} // переменная s определена только внутри функции sum

void test_swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
} // это не сработает, тк. мы работаем с копиями переменных

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
} // вот так работает правильно, мы передаем указатели

void main() {
  // вот здесь переменная s не определена
  // s = 42; - приведет к ошибке
  int x = 42;
  int y = 618;

  int c = 0;
  c = sum(x, y);
  // c == 660

  test_swap(x, y);
  printf("%d %d\n", x, y);

  swap(&x, &y);
  printf("%d %d", x, y);
}

// бонус: функция swap без переменной temp
// если вы читаете это за пару часов до экзамена то забейте
void swap2(int* a, int* b) {
  *a += *b; *b = *a - *b; *a -= *b;
}