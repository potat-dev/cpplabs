// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

// If cyrillic symbols are broken:
// ctrl + shift + P -> Change file rncoding -> Reopen with encoding -> Windows 1251

#define USE_RUS 0 // 1 - yes

#include <stdio.h>
#include <stdlib.h>
#if USE_RUS == 1
#include <locale.h>
#endif

#define length(x) (sizeof(x) / sizeof((x)[0]))
int len = 0;

char *readstr()
{
  len = 0;
  int capacity = 1;                       // емкость динамической строки
  char *s = (char *)malloc(sizeof(char)); // динамическая пустая строка
  char c = getchar();
  while (c != '\n')
  {
    s[(len)++] = c;
    if (len >= capacity)
    {                                                  // если реальный размер больше размера контейнера, то увеличим его размер
      capacity *= 2;                                   // увеличиваем емкость в два раза
      s = (char *)realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной емкостью
    }
    c = getchar();
  }
  s[len] = '\0';
  return s; // возвращаем указатель
}

void print_char(char ch)
{
  switch (ch)
  {
  case '.':
    printf(USE_RUS == 1 ? "ТЧК" : "DOT");
    break;
  case ',':
    printf(USE_RUS == 1 ? "ЗПТ" : "COMMA");
    break;
  case '!':
    printf(USE_RUS == 1 ? "ВСКЛ" : "EXCLM");
    break;
  case '?':
    printf(USE_RUS == 1 ? "ВПРС" : "QSTN");
    break;
  case ':':
    printf(USE_RUS == 1 ? "ДВТЧ" : "COLON");
    break;
  default:
    printf("%c", ch);
    break;
  }
}

void main()
{
#if USE_RUS == 1
  setlocale(LC_ALL, "Russian");
  system("chcp 1251");
#endif

  printf(USE_RUS == 1 ? "Введите строку:\n" : "Input string:\n");
  char *str = readstr(); // считываем динамическую строку
  printf(USE_RUS == 1 ? "\nСтрока после замены:\n" : "\nString after replace:\n");
  for (int i = 0; i < len; i++)
    print_char(str[i]);
  free(str);
}