// Ввести целое число N. Вывести число,
// полученное из введенного инверсией каждого
// 4-го двоичного разряда (начиная с младших)

// доп: определить, каждый какой бит инвертирован

#include "lab.h"
#define DOP

#ifdef DOP

  int main() {
    // вводим сдвиг для инвертирования
    unsigned int offset;
    printf("offset: ");
    scanf("%u", &offset);

    // вводим исходное число
    unsigned int in;
    printf("input: ");
    scanf("%u", &in);
    printf("bin: ");
    print_bin(in);
    printf("\n\n");

    // инвертируем биты числа
    unsigned int out = invert_every_nth(in, offset);
    printf("output: %u\nbin: ", out);
    print_bin(out);
    printf("\n\n");

    // определяем разницу и сдвиг
    printf("dif: ");
    print_bin(in ^ out);
    printf("\noffset: %d\n", get_invert_offset(in, out));
  }

#else

  int main() {
    // вводим исходное число
    unsigned int N;
    scanf("%u", &N);

    // инвертируем каждый 4-й бит
    printf("%u", invert_4(N));
  }

#endif