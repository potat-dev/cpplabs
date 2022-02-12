int gen() {
  static int f0 = 1, f1 = 1, f2 = 1, f = 0; 
  f = (f0 + f1 + f2) % 211;
  f0 = f1; f1 = f2; f2 = f;
  return f;
}

// int gen() {
//   static int f1 = 1, f2 = 1, f3 = 0; 
//   f3 = (f2 + f1) % 211;
//   f1 = f2;
//   f2 = f3;
//   return f3;
// }