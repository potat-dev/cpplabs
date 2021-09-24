// Ввести 10 действительных чисел, вывести максимальное по абсолютной величине число

#include <stdio.h>
#include <stdlib.h>

void main() {
    long int n, max = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%ld", &n);

        if (abs(n) > max) {
            max = abs(n);
        }
    }

    printf("%ld", max);
}