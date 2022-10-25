#pragma once

// изменено на my_strcmp для избежания конфликта с библиотечной функцией
int my_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const char *)s1 - *(const char *)s2;
}

// от последнего символа 2 строки отнимается
// последний символ 1 строки