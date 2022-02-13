#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
    FILE* f;
    char* buffer = 0;
    char** lines = 0;
    long length;
    long prevPos;
    long currentLine;
    long i;

    f = fopen("file.txt", "r");

    if (!f) {
        printf("failed to open file");
        exit(42);
    }

    // Определяем размер файла
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Выделяем массив данного размера
    buffer = malloc(length);
    if (buffer) {
        // Читаем весь файл в массив
        fread(buffer, 1, length, f);
    }
    fclose(f);

    if (!buffer) {
        printf("read nothing");
        exit(42);
    }

    long linesCount = 1;
    // Считаем количество строчек,
    for (i = 0; i < length; i++) {
        if (buffer[i] == '\n') {
            linesCount++;
        }
    }

    printf("Lines count: %d\n", (int)linesCount);

    // Выделяем память под указатели на строчки
    lines = malloc(linesCount * sizeof(char*));
    currentLine = 0;
    prevPos = 0;
    for (i = 0; i < length; i++) {
        if (buffer[i] == '\n' || i == length - 1) {
            lines[currentLine] = malloc(i - prevPos + 1);
            memcpy(lines[currentLine], &buffer[prevPos], i - prevPos);
            lines[currentLine][i - prevPos] = 0; // Последний символ в строке 0
            prevPos = i + 1; // +1 для windows (там где \r\n)
            currentLine++;
        }
    }
    free(buffer);

    // Имеем массив lines в котором linesCount строк
    for (i = 0; i < linesCount; i++) {
        printf("%s\n", lines[i]);
    }


    // Не забыть освободить нааллоцированное:
    for (i = 0; i < linesCount; i++) {
        free(lines[linesCount]);
    }
    free(lines);

    return 0;
}