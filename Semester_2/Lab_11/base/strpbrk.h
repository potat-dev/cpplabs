#pragma once

// изменено на my_strpbrk для избежания конфликта с библиотечной функцией
const char *my_strpbrk(const char *string, const char *chars) {
  char *temp = (char *)string;
  while (*temp != 0) {
    for (int i = 0; chars[i] != 0; i++)
      if (*temp == chars[i]) return temp;
    temp++;
  }
  return nullptr;
}

// ищет в строке string символы из строки chars
// возвращает указатель на первый найденный символ в строке string