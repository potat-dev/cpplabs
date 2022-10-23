#pragma once

#define NULL __null

const char *strpbrk(const char *string, const char *chars) {
  char *temp = (char *)string;
  while (*temp != 0) {
    for (int i = 0; chars[i] != 0; i++)
      if (*temp == chars[i]) return temp;
    temp++;
  }
  return NULL;
}

// ищет в строке string символы из строки chars
// возвращает указатель на первый найденный символ в строке string