// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье
// (нерекурсивный вариант)

#pragma once

#include <complex>
#include <vector>

typedef std::complex<double> base;

void fft(std::vector<base> &a, bool invert);
std::vector<uint16_t> multiply(std::vector<uint16_t> const &a,
                               std::vector<uint16_t> const &b);
