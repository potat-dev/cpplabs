// npos --- общее число знаков (включая запятую)
// nfr --- число знаков после запятой

#include <stdlib.h>
#include <stdio.h>

// char* dtoa(double num, int npos, int nfr);

/*
char* dtoa(double _num, int _npos, int _prec)
{
    int size = 0;
    if (_num < 0) {
        size = _npos + _prec + 3;
        _num = -_num;
    } else {
        size = _npos + _prec + 2;
    }

    char* num = (char*)malloc(size * sizeof(char));
    int cel = int(_num); double ost = _num - cel;
    num[_npos] = ',';
    for (int i = _npos - 1; i >= 0; --i, cel /= 10)
        num[i] = cel % 10 + 48;
    for (int i = _npos + 1; i < size; ++i) {
        num[i] = (int)(ost * 10) + 48;
        ost *= 10;
        ost -= int(ost);
    }
    num[size - 1] = '\0';
    for (int i = 0; i <= _npos; i++) {
        num[i] = num[i + _prec + 1];
    }
    num[_npos + 1] = '\0';

    if (_num < 0) {
        for (int i = _npos; i > 0; i--) {
          num[i + i] = num[i];
        }
        num[0] = '-';
    }

    return num;
}
*/

int after_decimal(double d) {
	int temp = (int)d;
	int count = 0;
	while (temp != d) {
		count++;
		d *= 10;
		temp = (int)d;
	}
	return count;
}

int digits_count(double d) {
  // считает кол-во цифр
  // не считает точку и знак минус
  int count = after_decimal(d);
  int temp = (int)d;
  while (temp) {
    temp /= 10;
    count++;
  }
  return count;
}