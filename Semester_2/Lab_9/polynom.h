struct polynom;
polynom *new_polynom(int *arr, int n);
polynom *new_binom(int a);
polynom *multiply(polynom *a, polynom *b);
void print_polynom(polynom *p);
void destroy(polynom *p);