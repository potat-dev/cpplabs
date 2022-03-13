#include "frand.h"

#define frand() ((float)(rand())/(RAND_MAX))

// округление: i <= f < i+1
int round(float f) { 
  return (int)(f > 0 ? f : f - 1);
}

// [-n ... n]
float frand_n(int n) {
  return frand() * n * 2 - n;
}

// [-n ... n] норм. распределение
// Центральная Предельная теорема
float normal_frand_n(int count, int n) {
  float sum = 0;
  for (int i = 0; i < count; i++)
    sum += frand_n(n);
  return sum / count;
}
