// Ввести 10 действительных чисел, вывести максимальное по абсолютной величине число
// доп. задание: вывести все локальные максимумы

#include <stdio.h>
#include <stdlib.h>

void main() {
    int flag = 0;
    int arr[10] = {0};

    printf("Input 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%ld", &arr[i]);
    }

    for (int i = 1; i < 9; i++) {
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
            flag = 1;
            printf("%d ", arr[i]);
        }
    }

    if(!flag) {
        printf("There are no local max values :(\n");
    }
}