// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#pragma once

#include <complex>
#include <vector>

typedef std::complex<double> base;

void fft(std::vector<base> &a, bool invert);
std::vector<long> multiply(std::vector<long> const &a, std::vector<long> const &b);
