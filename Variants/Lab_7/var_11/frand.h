#pragma once

#include <stdio.h>
#include <stdlib.h>

// случайное число в диапазоне [0, 1]
#define frand() ((float)(rand())/(RAND_MAX))

// округление: i <= f < i+1
#define round(f) (int)(f > 0 ? f : f - 1)

// случайное число в диапазоне [-n ... n]
#define frand_n(n) (frand() * n * 2 - n)

// случайное число в диапазоне [-n ... n],
// с нормальным распределением, используя
// Центральную Предельную теорему
float normal_frand_n(int count, int n);

// красивый вывод на экран
void pretty_print(int *arr, int n, int wide);