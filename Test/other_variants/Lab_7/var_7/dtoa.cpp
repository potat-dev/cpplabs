// npos --- общее число знаков (включая запятую)
// nfr --- число знаков после запятой

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int digit_count(int n) {
  int digit_count = 1;
  while (n /= 10) digit_count++;
  return digit_count;
}

// from stackoverflow //
// https://stackoverflow.com/a/50710965/15301038

char *dtoa(double num, int npos, int nfr) {
  int num_int = abs(round(num * pow(10, nfr)));

  if (num_int == 0) {
    char *s = (char *)malloc((nfr + 3) * sizeof(char));
    s[0] = '0';
    s[1] = '.';
    for (int i = 2; i < nfr + 2; i++) s[i] = '0';
    s[nfr + 2] = '\0';
    return s;
  }

  int size = digit_count(num_int) + 1 + (nfr > 0) + (num < 0);
  char *s = (char *)malloc(size * sizeof(char));

  for (int i = 0, n = num_int; n != 0; n /= 10) {
    s[size - 2 - i++] = n % 10 + 48;
    if (nfr > 0 && i == nfr)
      s[size - 2 - i++] = '.';
  }
  s[size - 1] = '\0';
  if (num < 0) s[0] = '-';
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