// Ввести строку
// Вывести различные слова вместе с количеством их появления в строке

// КОД НИЖЕ НЕ РАБОТАЕТ
// это файл чисто для тестов

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 50
#define WORDS_LEN 30
#define STR_LIMIT (WORDS_LEN + 1) * WORDS_LIMIT

#define strlen(x) (sizeof(x) / sizeof((x)[0]))

int is_char(char c) {
    return ((65<=c && c<=90)
        ||  (97<=c && c<=122)
        || (128<=c && c<=175)
        || (224<=c && c<=239)) ? 1 : 0; }

int strcmp(char s1[], char s2[]) { // аналог функции strcmp в string.h
  for (int i = 0; ; i++) {
    if (s1[i] != s2[i]) return 1; // строки не совпадают
    if (s1[i] == '\0')  return 0; // строки совпадают
} }

void strcopy(char *dest, const char *src) { // аналог функции strcpy в string.h
  char *p = dest;
  do *p++ = *src; // колпируем каждый символ из src в dest
  while (*src++);
}

// посимвольное получение динамической строки с пробелами c получением её реальной длины
char *get_string(int *len) {
    *len = 0;                               // изначально строка пуста
    int capacity = 1;                       // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    char *s = (char *)malloc(sizeof(char)); // динамическая пустая строка
    char c = getchar(); // символ для чтения данных
    // читаем символы, пока не получим символ переноса строки (\n)
    while (c != '\n') {
        s[(*len)++] = c; // заносим в строку новый символ
        // если реальный размер больше размера контейнера, то увеличим его размер
        if (*len >= capacity) {
            capacity *= 2;                                   // увеличиваем ёмкость строки в два раза
            s = (char *)realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью
        }
        c = getchar(); // считываем следующий символ
    }
    s[*len] = '\0'; // завершаем строку символом конца строки
    return s; // возвращаем указатель на считанную строку
}

void main() {
  int len = 0;
  printf("Enter a string:\n");
  char *str = get_string(&len); // считываем динамическую строку
  printf("You've wrote: '%s', symbols: %d\n", str, len); // выводим строку и её длину
  char words[WORDS_LIMIT][WORDS_LEN + 1] = {0};
//   char str[STR_LIMIT] = {0};

//   fgets(str, STR_LIMIT, stdin);
  printf("\nWords:\n--------\n");

  int word = 0, k = 0;
  for (int i = 0; i <= strlen(str); i++) {
    if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
      words[word][k] = '\0';
      if (str[i] != '\n') {
        word++;
      } else { break; }
      k = 0;
    } else if (is_char(str[i])) {
      words[word][k] = str[i];
      k++;
  } }

  int flag = 0;
  for (int w = 0; w <= word + 1; w++) {
    int count = 1;

    for (int i = 0; i <= word + 1; i++) {
      if (strcmp(words[i], words[w]) == 0 && w != i && strcmp(words[i], "\0") != 0) {
        strcopy(words[i], "\0");
        count++; } }
    if (strcmp(words[w], "\0") != 0) printf("%s - %d times\n", words[w], count);
  }
  free(str); // освобождаем динамическую память
}

// выше была жалкая попытка оптимизации работы программы
// а ниже будет много неиспользованного говнокода, который мне жаль удалять


///// shitty code ////////
// int strcmp(const char* s1, const char* s2)
// {
//     while (*s1 && (*s1 == *s2))
//         s1++, s2++;
//     return *(const unsigned char*)s1 - *(const unsigned char*)s2;
// }

// int strcmp(const char *str1, const char *str2)
// {
//     int s1;
//     int s2;
//     do {
//         s1 = *str1++;
//         s2 = *str2++;
//         if (s1 == 0)
//             break;
//     } while (s1 == s2);
//     return (s1 < s2) ? -1 : (s1 > s2);
// }

// void sort_words(char *words[], int *counts[], int count) {
//     char x[WORDS_LEN];
//     int y;
//     for (int i = 0; i<count; i++)
//     {
//         for (int j = i + 1; j<count; j++)
//         {
//             if (strcmp(words[i], words[j]) < 0)
//             {
//               strcopy(x, words[j]);
//               strcopy(words[j], words[i]);
//               strcopy(words[i], x);
//               strcopy(y, counts[j]);
//               strcopy(counts[j], counts[i]);
//               strcopy(counts[i], y);
//             }
//         }
//     }
// }

// int strcmp(char s1[], char s2[]) { // аналог функции strcmp в string.h
//   for (int i = 0; ; i++) {
//     if (s1[i] != s2[i]) return 1; // строки не совпадают
//     if (s1[i] == '\0')  return 0; // строки совпадают
// } }

// char x[WORDS_LEN];
// int y;
// for (int i = 0; i<=curr_w; i++)
// {
//     for (int j = i + 1; j<=curr_w; j++)
//     {
//         if (strcmp(words[i], words[j]) < 0)
//         {
//           strcopy(x, words[j]);
//           strcopy(words[j], words[i]);
//           strcopy(words[i], x);
//           y = counts[j];
//           counts[j] = counts[i];
//           counts[i] = y;
//         }
//     }
// }