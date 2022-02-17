// нужна прога с двумерным динамическим массивом,
// которая исполняет вот это вот:
// вводишь строку и слово, а прога выводит эту же строку,
// но после каждого слова, содержащего то слово,
// которое ты ввёл, прога выводила бы "---" 

// пример: 
// hello world gell, ell 
// hellо--- world gell---

#include <stdio.h>
#include <stdlib.h>

int len = 0;

int strlen(char *str) { // определяем длину строки
  int count = 0;
  for (int i = 0; str[i] != 0; i++) count++;
  return count;
}

void strcopy(char* to, const char* from, size_t n) {
  while(n--) // копируем n символов
    *(to++) = *(from++); // из одной строки в другую
}

int strcmp(char *s1, char *s2) {
  for (int i = 0; i < strlen(s2); i++) // пока не дойдем до конца второго слова
    if (s1[i] != s2[i]) // сравниваем каждую букву
      return 0; // не совпадают
  return 1; // совпадают
}

char *readstr() { // оптимальный ввод слова в динамическую память
  len = 0;
  int capacity = 1;
  char *s = (char *)malloc(sizeof(char));
  char c = getchar(); // получаем введенный символ
  while (c != '\n') { // пока не найдем конец ввода
    s[(len)++] = c;
    if (len >= capacity) { // если памяти не хватает
      capacity *= 2; // выделяем в 2 раза больше памяти
      s = (char *)realloc(s, capacity * sizeof(char));
    }
    c = getchar();
  }
  s[len] = 0; // в конце введенной строки всегда \0
  len += 1;
  return s; // возвращаем указатель на строку
}

int main (int argc, char *argv[]) {
  printf("Enter string:\n");
  char *str = readstr(); // считываем строку в динамическую память
  int str_len = len;

  printf("\nEnter word:\n");
  char* word = readstr(); // считываем слово в динамическую память
  int word_len = len;
  printf("\n");

  int words_count = 0;
  for (int i = 0; i < str_len; i++)
    if (str[i] == ' ' || str[i] == 0)
      words_count++; // определяем количество слов
  
  char** words = malloc(words_count * sizeof(char*)); // выделяем массив указателей на слова
  
  int curr_word = 0, pos = 0;
  for (int i = 0; i < str_len; i++) { // проходим по всей строке
    if (str[i] == ' ' || str[i] == 0) { // если нашли новое слово
      words[curr_word] = malloc(i - pos + 1); // выделяем память на одно слово
      strcopy(words[curr_word], &str[pos], i - pos); // записываем его в двумерный массив
      words[curr_word][i - pos] = 0; // последний символ в слове - \0
      pos = i + 1;

      for (int i = 0; i <= strlen(words[curr_word]) - strlen(word); i++) // проходим по срезам слова (abcd, bcd, cd, d)
        if (strcmp(words[curr_word]+i, word)) { // проверяем на соответствие нужной подстроке
          curr_word++;
          words_count++;
          words = realloc(words, (words_count) * sizeof(char*));
          words[curr_word] = malloc(sizeof(char) * 4);
          strcopy(words[curr_word], "---", 4);
          break; // выходим из цикла проверки срезов
        }
      curr_word++;
    }
  }

  for (int w = 0; w < words_count; w++) printf("%s ", words[w]);
}