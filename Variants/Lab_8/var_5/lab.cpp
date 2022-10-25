#include "lab.h"

int gen(int a, int b) {
	int c = ("%d\n", a + rand() % (b - a + 1));
	printf("%d, ", c);
	return c;
}

void sort(int size, int* mas) {
	int arr[10000] = { 0 };

	for (int i = 0; i < size; i++)
		arr[mas[i]]++;

	int k = 0;
	for (int i = 0; i < 10000; i++)
		while (arr[i]--)
			mas[k++] = i;
}