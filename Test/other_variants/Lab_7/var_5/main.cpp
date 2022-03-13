// Написать генератор псевдослучайных чисел, распределенных на интервале[0, 10).
// Подсчитать и вывести частоты попадания в каждый из единичных интервалов при выборке 100000
// использовать rand()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));
  int a, capacity = 0;
  printf("Enter a number of random numbers \n");
  scanf("%d", &a);
  while (capacity >= a);
  capacity *= 2;
  int *mas = (int *)malloc(capacity * sizeof(int));
  for (int i = 0; i < a; i++)
  {
    int r = rand() % 10;
    mas[i] = r;
  }
  for (int i = 0; i < a; i++)
    printf("%d, ", mas[i]);
}