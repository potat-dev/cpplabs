// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#pragma once

#include <complex>
#include <vector>

typedef std::complex<double> base;

void fft(std::vector<base> &a, bool invert);
std::vector<int> multiply(std::vector<int> const &a, std::vector<int> const &b);
