// npos --- общее число знаков (включая запятую)
// nfr --- число знаков после запятой

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int after_decimal(double d) {
  d = (d > 0) ? d : -d;
	unsigned long long temp = (unsigned long long) d;
	int count = 0;
	while (temp != d) {
		count++;
		d *= 10;
		temp = (unsigned long long)d;
	}
	return count;
}

int digits_count(double d) {
  // считает кол-во цифр
  // не считает точку и знак минус
  int count = after_decimal(d);
  unsigned long long temp = (unsigned long long) (d > 0 ? d : -d);
  while (temp) {
    temp /= 10;
    count++;
  }
  return count;
}

int double_length(double d) {
  // считает кол-во цифр
  // считает точку и минус
  int count = after_decimal(d);
  count += (count > 0) + (d < 0);
  unsigned long long temp = (unsigned long long)(d > 0 ? d : -d);
  while (temp) {
    temp /= 10;
    count++;
  }
  return count;
}

int before_decimal(double d) {
  d = (d > 0) ? d : -d;
  unsigned long long temp = (unsigned long long) d;
  int count = 0;
  while (temp) {
    temp /= 10;
    count++;
  }
  return count;
}

int digits_count(int n) {
  int digit_count = 1;

  if (n >= 100000000) {
    digit_count += 8;
    n /= 100000000;
  }
  if (n >= 10000) {
    digit_count += 4;
    n /= 10000;
  }
  if (n >= 100) {
    digit_count += 2;
    n /= 100;
  }
  if (n >= 10) {
    digit_count++;
  }
  return digit_count;
}

// from stackoverflow //
// https://stackoverflow.com/a/50710965/15301038

char *dtoa(double num_double, int decimal_place) {
  int num_int = abs(round(num_double * pow(10, decimal_place)));

  if (num_int == 0) {
    char *s = (char *)malloc((decimal_place + 3) * sizeof(char));
    s[0] = '0';
    s[1] = '.';
    for (int i = 2; i < decimal_place + 2; i++) s[i] = '0';
    s[decimal_place + 2] = '\0';
    return s;
  }

  int size = digits_count(num_int) + 1 + (decimal_place > 0) + (num_double < 0);
  char *s = (char *)malloc(size * sizeof(char));

  for (int i = 0, n = num_int; n != 0; n /= 10) {
    s[size - 2 - i++] = n % 10 + 48;
    if (decimal_place > 0 && i == decimal_place)
      s[size - 2 - i++] = '.';
  }
  s[size - 1] = '\0';
  if (num_double < 0) s[0] = '-';
  return s;
}

/*
char* dtoa(double num, int npos, int nfr) {
  char* str = (char*) malloc((npos + 1) * sizeof(char));
  num = (num > 0) ? num : -num;
  unsigned long long temp = (unsigned long long) num;
  int before = before_decimal(num);

  int pos = 0;
  if (num < 0) {
    str[pos] = '-';
    pos++;
  }
  for (int i = pos; i < pos + before; pos++) {
    str[pos] = ();
  }
  return str;
}
*/