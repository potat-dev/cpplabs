// Написать функцию, которая вставляет в массив элемент с заданным индексом и заданным значением.
// Лишний элемент должен пропасть.

#include <stdio.h>

#define len(x) (sizeof(x) / sizeof((x)[0]))
#define SIZE 15

void insert(int size, int *arr, int index, int value) {
    if (index >= 0 && index < size) {
        for (int i = size - 1; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
    } else { printf("Index out of range\n"); }
}

void main() {
    int arr[SIZE];
    int id = 0, val = 0;

    for(int i = 0; i < SIZE; i++) arr[i] = i; // наполлняем тестовый массив

    printf("Original array:\n[ ");
    for(int i = 0; i < SIZE; i++) printf("%d ", arr[i]);

    printf("]\n\nEnter Index and Value to insert: ");
    scanf("%d %d", &id, &val);

    insert(len(arr), arr, id, val); // используем функцию

    printf("\nArray after insert:\n[ ");
    for(int i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    printf("]\n\n");
}