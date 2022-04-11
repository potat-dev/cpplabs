int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const char *)s1 - *(const char *)s2;
}

// от последнего символа 2 строки отнимается
// последний символ 1 строки