#pragma once

// выдает случайное число из промежутка [0..1]
#define rand_1 ((float)(rand()) / (RAND_MAX))

// инициализация генератора
void rand_init();

// генератор нормально распределенного
// случайного числа в промежутке [0..n]
double frand(double n, int count);