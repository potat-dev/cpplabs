#include <stdio.h>
#include <stdlib.h>

#define S 100
#define W 10

int strCompare(char *s1, char *s2)
{
  while ((*s1 == *s2) && (*s1 != 0))
  {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

void delN(char *s) // удаляем перенос строки в конце слова
{
  int i = 0;
  while ((s[i] != '\n') && (s[i] != 0))
    i++;
  s[i] = 0; // заменяем на символ конца строки
}


int main()
{
  printf("Enter first word: ");
  char firstWord[W] = {0};
  fgets(firstWord, W, stdin);
  delN(firstWord);

  int lenW1 = 0;
  while (firstWord[lenW1] != 0)
    lenW1++;

  printf("\n");

  printf("Enter second word: ");
  char secondWord[W] = {0};
  fgets(secondWord, W, stdin);
  delN(secondWord);

  int lenW2 = 0;
  while (secondWord[lenW2] != 0)
    lenW2++;

  printf("\n");

  printf("Enter string: ");
  char str[S] = {0};
  fgets(str, S, stdin);
  delN(str);

  int lenStr = 0;
  while (str[lenStr] != 0)
    lenStr++;

  int wordsCount = 0;
  char **words = (char **)malloc(sizeof(char *) * (wordsCount + 1));

  int tmp = 0;
  words[wordsCount] = (char *)malloc(sizeof(char) * (tmp + 1));
  for (int i = 0; i < lenStr; i++)
  {
    if (str[i] != ' ')
    {
      words[wordsCount][tmp] = str[i];
      tmp++;
      char *temp = words[wordsCount];
      temp = (char *)realloc(temp, sizeof(char) * (tmp + 1));
      words[wordsCount] = temp;

      if (i == lenStr - 1)
        goto endwords;
    }
    else if (str[i] == ' ')
    {
    endwords:
      words[wordsCount][tmp] = 0;
      tmp = 0;
      char *temp_word = words[wordsCount];
      wordsCount++;
      words = (char **)realloc(words, sizeof(char *) * (wordsCount + 1));
      words[wordsCount] = (char *)malloc(sizeof(char) * (tmp + 1));
    }
  }

  for (int i = 0; i < wordsCount; i++)
  {
    printf("%s ", words[i]);
    if (strCompare(words[i], firstWord) == 0)
      printf("%s ", secondWord);
  }

  return 0;
}