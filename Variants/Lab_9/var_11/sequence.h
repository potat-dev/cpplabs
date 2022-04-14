#pragma once

#include "stdio.h"
#include "stdlib.h"

// подсчет количества значащих бит в числе
int count_bits(unsigned long long N);

// конвертация uint64 в массив бит
char *dtoab(unsigned long long N);

// нахождение длины максимальной
// последовательности из единиц
int count_max_ones(unsigned long long N);