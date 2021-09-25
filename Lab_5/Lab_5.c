// Ввести строку. Заменить знаки препинания на сокращения
// ('.' - тчк, ',' - зпт, '?' - впр, ':' - дтч)

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x) / sizeof((x)[0]))

int len = 0;

char *readstr() {
    len = 0;
    int capacity = 1; // емкость динамической строки
    char *s = (char*)malloc(sizeof(char)); // динамическая пустая строка

    char c = getchar();
    while (c != '\n') {
        s[(len)++] = c;
        if (len >= capacity) { // если реальный размер больше размера контейнера, то увеличим его размер
            capacity *= 2;     // увеличиваем емкость в два раза
            s = (char*)realloc(s, capacity*sizeof(char)); // создаём новую строку с увеличенной емкостью  
        }
        c = getchar();          
    }
    s[len] = '\0';
    return s; // возвращаем указатель
}

void main() {
    char *str = readstr(); // считываем динамическую строку
    printf("You've wrote: '%s', symbols: %d\n", str, len);
    free(str);
}