// npos --- общее число знаков (включая запятую)
// nfr --- число знаков после запятой

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

char *dtoa(double num, int npos, int nfr) {
  int inum = abs(round(num * pow(10, nfr)));
  char *s = (char *)malloc((npos + 1) * sizeof(char));
  for (int i = 0; i < npos; i++) s[i] = '0';
  s[npos] = '\0';

  if (inum == 0) {
    s[1] = '.';
    return s;
  }

  if (num < 0) s[0] = '-';
  int n = inum, digit_count = 1;
  while (n /= 10) digit_count++;
  int size = digit_count + 1 + (nfr > 0) + (num < 0);
  for (int i = 0, n = inum; n != 0; n /= 10) {
    s[size - 2 - i++] = 48 + n % 10;
    if (nfr > 0 && i == nfr)
      s[size - 2 - i++] = '.';
  }

  return s;
}