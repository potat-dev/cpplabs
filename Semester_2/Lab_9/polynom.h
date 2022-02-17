struct polynom;

polynom *new_polynom(long long *arr, unsigned int n);
void upd_polynom(polynom *p, long long *arr, unsigned int n);
polynom *new_binom(long long a);
void upd_binom(polynom *b, long long a);
polynom *multiply(polynom *a, polynom *b);
void multiply(polynom *m, polynom *a, polynom *b);
void print_polynom(polynom *p);
void print_koeffs(long long *arr, unsigned int n);
void destroy(polynom *p);