#include <stdio.h>
int main()
{
  unsigned long long k = 0, raz = 0, i = 1;
  float a = 0, n = 0, C = 1;
  printf("Enter n=");
  scanf("%f", &n);
  printf("Entenr k=");
  scanf("%d", &k);
  raz = n - k;
  while (i <= raz)
  {
    a = (n - (i - 1)) / i;
    C = C * a;
    i++;
  }
  printf("C=%f", C);
}