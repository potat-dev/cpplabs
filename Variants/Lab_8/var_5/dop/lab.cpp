#include "lab.h"

void sort(int size, int* mas) {
	int arr[10000] = { 0 };

	for (int i = 0; i < size; i++)
		arr[mas[i]]++;

	int k = 0;
	for (int i = 0; i < 10000; i++)
		while (arr[i]--)
			mas[k++] = i;
}

double ran_expo(double lambda) {
    double u;
    u = rand() / (RAND_MAX + 1.0);
    return -log(1 - u) * lambda;
}

// int main(void)
// {
//     int i;
//     srand((unsigned)time(NULL));
//     for (i=0; i<20; i++)
//         printf("%f\n", ran_expo(0.05));
//     return 0;
// }