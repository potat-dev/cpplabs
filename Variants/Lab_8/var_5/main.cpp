// Ввести длину массива натуральных чисел и диапазон его значений
// (минимально возможное и максимально возможное значения).
// Ввести массив. Вывести упорядоченный массив при помощи сортировки подсчётом...
// сделать по экспоненциальному закону распределения

#include "lab.h"

void main() {
	int size = 0, min = 0, max = 0, capacity = 1, razn = 0;
	printf("Enter the length of the array:\n");
	scanf("%d", &size);

	while (capacity < size)	capacity *= 2;
	int* mas = (int*) malloc(capacity * sizeof(int));
	
	printf("Enter the min & max elements:\n");
	scanf("%d %d", &min, &max);

	for (int i = 0; i < size; i++)
		mas[i] = gen(min,max);

	sort(size, mas);

	printf("\n\n");
	for (int i = 0; i < size; i++)
		printf("%d ", mas[i]);

	free(mas);
}