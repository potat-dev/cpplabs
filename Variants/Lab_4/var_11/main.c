// Ввести строку и слово
// Вывести порядковые номера слов в строке, совпадающих с введенным словом

// В данной лабораторной работе можно использовать допущение о максимальной длине строки,
// чтобы не использовать динамическую память. (с) файл с заданиями

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIM 50 // максимальное количество слов
#define WORDS_LEN 31 // макс длина слова (30 chars + "\0")

#define STR_LIMIT WORDS_LIM * WORDS_LEN     // максимальная длина строки
#define len(x) (sizeof(x) / sizeof((x)[0])) // длина массива

int strlen(char *str) { // функция вычисления длины слова
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) // ищем конец строки
    count++;
  return count;
}

int is_char(char c) { // известная всем функция проверки букв
  return ((65<=c && c<=90)||(97<=c && c<=122)||(128<=c && c<=175)||(224<=c && c<=239));
}

int strcmp(char s1[], char s2[]) { // сравниваем два слова
  for (int i = 0; ; i++) {         // пробегаемся по всем символам
    if (s1[i] != s2[i]) return 1;  // строки не совпадают
    if (s1[i] == '\0')  return 0;  // строки совпадают
} }

void strcopy(char *dest, const char *src) { // аналог strcpy в string.h
  char *p = dest;
  do *p++ = *src; // копируем каждый символ из src в dest
  while (*src++); // пока не достигнем конца строки
}

void main() {
  char words[WORDS_LIM][WORDS_LEN] = {0}; // двумерный массив слов
  char str[STR_LIMIT] = {0};              // исходная строка
  char word[WORDS_LEN] = {0};             // введенное слово

  printf("Enter string: ");
  fgets(str, STR_LIMIT, stdin);  // вводим строку

  printf("Enter a word: ");
  fgets(word, WORDS_LEN, stdin); // вводим слово
  word[strlen(word)-1] = '\0';   // ставим конец слова вместо переноса строки

  printf("\nOutput: ");

  // разбиваем введенную строку на массив слов
  int count = 0, k = 0;
  for (int i = 0; i <= len(str); i++) { // проходимся по всей строке
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') { // если нашли пробел либо конец строки
      words[count][k] = '\0'; // завершаем запись текушего слова
      if (str[i] != '\n')     // если не достигли конца строки
        count++;              // переходим к следующему слову
      else
        break;
      k = 0;
    } else if (is_char(str[i])) {    // вводим только буквы, цифры пропускаем
      words[count][k] = str[i]; k++; // записываем букву в массив
    }
  }

  for (int w = 0; w <= count; w++) {   // проходим по всем словам в массиве
    if (strcmp(word, words[w]) == 0) { // если слова совпадают
      printf("%d ", w + 1);            // выводим его индекс, начиная с 1
    }
  }
}