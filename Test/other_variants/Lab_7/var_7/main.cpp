#include "dtoa.h"
#include <stdio.h>

// Написать функцию для преобразования переменной типа double в строку символов
// с заданной точностью представления dtoa(double num, int npos, int nfr)
// npos - общее число знаков (включая запятую)
// nfr - число знаков после запятой

int main() {
  double d1 = -39877789.141592;
  double d2 = 36549876;
  double d3 = -3.141592;
	
  printf("%f %d %d\n", d1, double_length(d1), after_decimal(d1));
  printf("%f %d %d\n", d2, double_length(d2), after_decimal(d2));
  printf("%f %d %d %d\n", d3, before_decimal(d3), double_length(d3), after_decimal(d3));
}