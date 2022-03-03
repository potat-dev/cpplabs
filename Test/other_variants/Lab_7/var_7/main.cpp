#include "dtoa.h"
#include <stdio.h>

// Написать функцию для преобразования переменной типа double в строку символов с заданной точностью
// представления(dtoa(double num, int npos, int nfr)) и тестирующую программу к ней, где npos— -
// общее число знаков(включая запятую), а nfr— - число знаков после запятой.

int main() {
  double d = -3.141592;
  printf("%d %d\n", digits_count(d), after_decimal(d));

}

/*
int main() {
	int npost = 0;
	int nfr = 0;
	double num;
	scanf("%lf", &num);
	nfr = posle(num);
	npost = k(num, nfr);
	printf("%d %d\n", npost, nfr);
	printf("%s\n", dtoa(num, npost, nfr));
	return 0;
}
*/