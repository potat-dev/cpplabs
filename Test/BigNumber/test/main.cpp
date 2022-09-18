// умножение длинных чисел

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Number {
  private:
    vector<char> digits;
    bool minus;

  public:
    Number(string num) {
      minus = (num[0] == '-');
      if (minus) num.erase(0, 1);
      for (char c: num) {
        if (is_num(c)) digits.push_back(c);
      }
    }

    Number(int64_t n): Number(to_string(n)) {}

    friend ostream& operator<<(ostream& out, const Number& n) {
      if (n.minus) out << '-';
      for (char i: n.digits) out << i;
      return out;
    }

    // оператор умножения длинных чисел с использованием быстрого преобразования фурье
    friend Number operator*(const Number& a, const Number& b) {
      int n = 1;
      while (n < a.digits.size() || n < b.digits.size()) n *= 2;
      n *= 2;

      vector<complex<double>> fa(n), fb(n);
      for (int i = 0; i < a.digits.size(); i++) fa[i] = a.digits[a.digits.size() - i - 1] - '0';
      for (int i = 0; i < b.digits.size(); i++) fb[i] = b.digits[b.digits.size() - i - 1] - '0';

      fft(fa, false);
      fft(fb, false);
      for (int i = 0; i < n; i++) fa[i] *= fb[i];
      fft(fa, true);

      vector<int> result(n);
      for (int i = 0; i < n; i++) result[i] = int(fa[i].real() + 0.5);
      for (int i = 0; i < n; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
      }

      int i = n - 1;
      while (i > 0 && result[i] == 0) i--;
      string s;
      while (i >= 0) s += char(result[i--] + '0');

      return Number(s);
    }

    bool is_num(char c) {
      return (47 < c && c < 58);
    }
};

int main() {
  Number n(-9859343);
  cout << n;
}