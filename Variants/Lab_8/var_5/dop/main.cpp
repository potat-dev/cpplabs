// Ввести длину массива натуральных чисел и диапазон его значений
// Ввести массив. Вывести упорядоченный массив при помощи сортировки подсчётом
// Сделать по экспоненциальному закону распределения

#include "lab.h"

int main() {
	int size = 0, koeff = 0, capacity = 1, razn = 0;
	printf("Enter the length of the array:\n");
	scanf("%d", &size);

	while (capacity < size) capacity *= 2;
	int* mas = (int*) malloc(capacity * sizeof(int));
	
	printf("Enter the exponential koeff:\n");
	scanf("%d", &koeff);

	for (int i = 0; i < size; i++)
		mas[i] = (int) ran_expo(koeff);

	sort(size, mas);

	printf("\n\n");
	for (int i = 0; i < size; i++)
		printf("%d ", mas[i]);

	free(mas);
}