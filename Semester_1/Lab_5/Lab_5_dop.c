// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

#include <stdio.h>
#include <stdlib.h>

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

int lenght(const char *s)
{
  int count = 0;
  while (*s != '\0')
  {
    count++;
    s++;
  }
  return count;
}

#define W_COUNT 5

void main() {
  char words[W_COUNT][6] = {"DOT", "COMMA", "EXCLM", "QSTN", "COLON"};
  char punct[W_COUNT] = {'.', ',', '!', '?', ':'};

for (int i = 0; i < W_COUNT; i++) {
  printf("%s - %d\n", words[i], lenght(words[i]));
}
  printf("Input string:\n");
  char *str = readstr(); // считываем динамическую строку (len - длина)

  printf("\nString after replace:\n");
  
  for (int i = 0; i < len; i++) {
    
  }


  // for (int i = 0; i < len; i++) {
  //   int ch_flag = 1; // нужно ли печатать букву
  //   for (int w = 0; w < W_COUNT; w++) {
  //     int flag = 0;
  //     for (int c = 0; c < lenght(words[w]); c++) {
  //       if (str[i + c] == words[c]) flag++;
  //     } ///////// что-то идет по пизде со счетчиком flag !!!!!!
  //     if (flag == lenght(words[w])) {  // если все буквы совпадают
  //       printf("%c", punct[w]);
  //       i += lenght(words[w])-1; // пропускаем оставшиеся буквы в слове
  //       ch_flag = 0; 
  //       break;
  //     }
  //   }
  //   if (ch_flag) printf("%c", str[i]);
  // }
}



  // for (int i = 0; i < len; i++) {

  //   if (str[i]   == 'D'  //
  //   &&  str[i+1] == 'O'  //
  //   &&  str[i+2] == 'T') //
  //   {                    //
  //     printf(".");       //
  //     i += 2;            //
  //     continue;          //
  //   }

  //   if (str[i]   == 'C'  //
  //   &&  str[i+1] == 'O'  // 
  //   &&  str[i+2] == 'M'  //
  //   &&  str[i+3] == 'M'  //
  //   &&  str[i+4] == 'A') // 
  //   {                    //
  //     printf(",");       // 
  //     i += 4;            //
  //     continue;          //
  //   }

  //   printf("%c", str[i]);
  // }