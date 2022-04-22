#pragma once

#include "stdio.h"
#include "stdlib.h"

// инвертирует каждый четвертый бит числа
unsigned int invert_4(unsigned int N);

// инвертирует каждый N-ый бит числа (32 bit)
unsigned int invert_every_nth(unsigned int N, unsigned int bit);

// определяет, каждый какой бит инвертирован
unsigned int get_invert_offset(unsigned int a, unsigned int b);

// красивый вывод двоичного числа на экран
void print_bin(unsigned int N);