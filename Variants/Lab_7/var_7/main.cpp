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
  double d4 = 0;
	
  printf("\n%f\n%s\n", d1, dtoa(d1, 16, 6));
  printf("\n%f\n%s\n", d2, dtoa(d2, 8, 0));
  printf("\n%f\n%s\n", d3, dtoa(d3, 9, 6));
  printf("\n%f\n%s\n", d4, dtoa(d4, 3, 1));
}