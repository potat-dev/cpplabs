#include <stdio.h>
#include <stdlib.h>

#define S 100
#define W 10

int len = 0;

int strlen(char *str) { // определяем длину строки
  int count = 0;
  for (int i = 0; str[i] != 0; i++) count++;
  return count;
}

int strCompare(char* s1, char* s2) {
  while ((*s1 == *s2) && (*s1 != 0))
  {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

void delN(char* s) {
  int i = 0;
  while ((s[i] != '\n') && (s[i] != 0)) i++;
  s[i] = 0;
}

int main() {

  printf("Enter first word: ");
  char firstWord[W] = { 0 };
  fgets(firstWord, W, stdin);
  delN(firstWord);

  int lenW1 = 0;
  while (firstWord[lenW1] != 0) lenW1++;


  char secondWord[4] = "---";
  int lenW2 = 4;

  printf("\n");
  printf("Enter string: ");
  char str[S] = { 0 };
  fgets(str, S, stdin);
  delN(str);

  int lenStr = 0;
  while (str[lenStr] != 0) lenStr++;

  int wordsCount = 0;
  char** words = (char**)malloc(sizeof(char*) * (wordsCount + 1));

  int tmp = 0;
  words[wordsCount] = (char*)malloc(sizeof(char) * (tmp + 1));
  for (int i = 0; i < lenStr; i++) {
    if (str[i] != ' ') {
      words[wordsCount][tmp] = str[i];
      tmp++;
      words[wordsCount] = (char*)realloc(words[wordsCount], sizeof(char) * (tmp + 1));

      if (i == lenStr - 1) goto endwords;
    }
    else if (str[i] == ' ') {
    endwords:
      words[wordsCount][tmp] = 0;
      tmp = 0;
      char* temp_word = words[wordsCount];
      if (strCompare(words[wordsCount], firstWord) == 0) {
        wordsCount++;
        words = (char**)realloc(words, sizeof(char*) * (wordsCount + 1));//+1
        words[wordsCount] = (char*)malloc(sizeof(char) * (lenW2 + 1));
        
        for (int i = 0; i <= lenW2; i++)
          words[wordsCount][i] = secondWord[i];

        wordsCount++;
      }
      else wordsCount++;
      words = (char**)realloc(words, sizeof(char*) * (wordsCount + 1));
      words[wordsCount] = (char*)malloc(sizeof(char) * (tmp + 1));
    }
  }
  for (int i = 0; i < wordsCount; i++) {
    printf("%s ", words[i]);
    
  }
  free(words);
  return 0;
}