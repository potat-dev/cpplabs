#include "frand.h"

float normal_frand_n(int count, int n) {
  float sum = 0;
  for (int i = 0; i < count; i++)
    sum += frand_n(n);
  return sum / count;
}