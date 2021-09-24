// Ввести три целых числа. Вычислить и вывести произведение первого и второго числа
// доп. задание: c умножить на b и поделить на a
// вывести резуультат как float

#include <stdio.h>

void main() {
    float a, b, c;
    printf("Input a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("c * b / a = %f\n", c * b / a);
}