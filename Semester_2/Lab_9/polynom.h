#pragma once
#include "fractions.h"

struct polynom {
  unsigned int n;   // количество коэффициентов
  fraction *koeffs; // массив коэффициентов (дробей)
};

polynom *new_polynom(long long *k, unsigned int n);
polynom *new_polynom(fraction *f, unsigned int n);
void upd_polynom(polynom *p, long long *k, unsigned int n);
polynom *new_binom(long long a);
void upd_binom(polynom *p, long long a);
polynom *multiply(polynom *a, polynom *b);
void multiply(polynom *m, polynom *a, polynom *b);
long long get_koeff(fraction *f);
void print_polynom(polynom *p);
void print_koeffs(long long *arr, unsigned int n);
void destroy(polynom *p);