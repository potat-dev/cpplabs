#pragma once

void rand_init();
#define rand_1 ((float)(rand()) / (RAND_MAX))

double frand(double n, int count);