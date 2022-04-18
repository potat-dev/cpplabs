#include <stdio.h>
#include <math.h>
#define N 5
#define D 3

unsigned char count_ones(unsigned char n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

int main()
{
    int M = 0; 
    int size = pow(2,N);
   int mark[size] = {0};
   int CodeBook[size] = {0};
   // шаг 1. Выбираем первое кодовое слово.
   CodeBook[0] = 0;
   // Отметим взятое слово в массиве пометок.
   mark[0] = 2;
   M++;
   // Шаг 2. \отметим все слова в кандатах на расстоянии меньше d от выбранного.
   for(int i = 0; i< size;i++)
   {
    if(mark[i] == 0 && (count_ones(i^CodeBook[M-1])<D))
     {
    mark[i] = 1;

                }
    printf("%d ", mark[i]);
    }
    printf("\n");

    //Шаг 1.
  // шаг 1. Выбираем второе кодовое слово.
  int zero = 0;
  for(zero = 0;  mark[zero]!= 0; zero++);
//printf("%d",zero);  
  CodeBook[M] = zero;
   // Отметим взятое слово в массиве пометок.
   mark[zero] = 2;
   M++;
   // Шаг 2. \отметим все слова в кандатах на расстоянии меньше d от выбранного.
   for(int i = 0; i< size;i++)
   {
    if(mark[i] == 0 && (count_ones(i^CodeBook[M-1])<D))
     {
    mark[i] = 1;

                }
    printf("%d ", mark[i]);
    }
  //Шаг 1.
  printf("\n");
  // шаг 1. Выбираем второе кодовое слово.
   zero = 0;
  for(zero = 0;  mark[zero]!= 0; zero++);
//printf("%d",zero);  
  CodeBook[M] = zero;
   // Отметим взятое слово в массиве пометок.
   mark[zero] = 2;
   M++;
   // Шаг 2. \отметим все слова в кандатах на расстоянии меньше d от выбранного.
   for(int i = 0; i< size;i++)
   {
    if(mark[i] == 0 && (count_ones(i^CodeBook[M-1])<D))
     {
    mark[i] = 1;

                }
    printf("%d ", mark[i]);
    }
printf("%d,%d,%d", CodeBook[0],CodeBook[1],CodeBook[2]);
   



    return 0;
}