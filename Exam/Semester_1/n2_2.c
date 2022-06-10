void main() {
  int a = 3;
  int b = 5;
  
  int c1 = a + b;
  int c2 = a - b;
  unsigned int c21 = a - b;
  int c3 = a * b;
  int c41 = a / b;
  float c42 = a / b;
  float c43 = ((float) a) / b;

  int d0 = ~a;
  int d1 = a & b;
  int d2 = a | b;
  int d3 = a ^ b;

  // побитовый сдвиг влево на 2
  int e_l = a << 2; // 00000011 << 00001100 (12)

  // побитовый сдвиг вправо на 1
  int e_r = b >> 1;  // 00000101 >> 00000010 (3)
} 