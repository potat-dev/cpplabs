#include <string>

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

int k(double acc, int st) {
	int cope;
	int cope2 = 0;
	int k = 10;
	int count = 0;
	for (int i = 0; i <= st; i++) {
		acc = acc * 10;
	}
	cope = acc;
	while (cope != cope2) {
		cope2 = cope % k;
		k = k * 10;
		count++;
	}
	return count;
}

int posle(double app) {
	int test = (int)app;
	int count = 0;
	while (test != app) {
		count++;
		app *= 10;
		test = (int)app;
	}
	return count;
}