#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
  if (n < 3) return (n == 2);
  if (~n & 1) return 0;
  for (int i = 3; i*i <= n; i += 2)
    if (n % i == 0) return 0;
  return 1;
}

int main (int argc, char *argv[]) {
  for (int i = 0; i < 10000; i++)
    if (is_prime(i))
      printf("%4d ", i);
}