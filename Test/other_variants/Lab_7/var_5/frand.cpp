#include "frand.h"

float frand10() {
  float f;
  do {
    f = frand();
  } while (f >= 1);
  return f * 10;
}