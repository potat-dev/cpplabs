#pragma once
#include "fractions.h"

struct polynom {
  unsigned int n;   // количество коэффициентов
  fraction *koeffs; // массив коэффициентов (дробей)
};

polynom *new_polynom(long long *k, unsigned int n);
polynom *new_polynom(fraction *f, unsigned int n);
polynom *new_binom(long long a);

void print_polynom(const char s[], polynom *p);
void print_koeffs(long long *arr, unsigned int n);

void upd_polynom(polynom *p, long long *k, unsigned int n);
void upd_binom(polynom *p, long long a);
void destroy(polynom *p);

polynom *multiply(polynom *a, polynom *b);
void multiply(polynom *m, polynom *a, polynom *b);
void integral(polynom *y, polynom *f);
