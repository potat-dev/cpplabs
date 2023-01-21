#include <stdio.h>

long long factor(long long a) {
  if ((a == 1) || (a == 0))
    return 1;
  else
    return (a * factor(a - 1));
}

long long multipl(long long a, long long b) {
  long long z = 1;
  for (int i = a; i <= b; i++)
    z = z * i;
  return z;
}

long long C_n_k(int n, int k) {
  return ((long long)(multipl(k + 1, n) / factor(n - k)));
}

long long closest(long long a) {
  int s = 0;
  while (a != 0) {
    a = a >> 1;
    s++;
  }
  return s - 1;
}

void test() {
  long long a, a_end;
  scanf("%llu", &a);
  
  a_end = closest(a);
  for (int i = 0; i <= a_end; i++)
    printf("With %d '1' is %d\n", i, C_n_k(a_end, i));
}