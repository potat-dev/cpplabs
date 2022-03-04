// npos --- общее число знаков (включая запятую)
// nfr --- число знаков после запятой

#include <stdlib.h>
#include <stdio.h>

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
  unsigned long long temp = (unsigned long long)(d > 0 ? d : -d);
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
    // str[pos] = ();
  }

  return str;
}