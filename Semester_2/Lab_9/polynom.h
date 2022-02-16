struct polynom;

polynom *new_polynom(int *arr, int n);
void upd_polynom(polynom *p, int *arr, int n);
polynom *new_binom(int a);
void upd_binom(polynom *b, int a);
polynom *multiply(polynom *a, polynom *b);
void multiply(polynom *m, polynom *a, polynom *b);
void print_polynom(polynom *p);
void destroy(polynom *p);