#include <iostream>
#include <vector>
using namespace std;

class HugeInt {
  public:
    HugeInt(string str = "0", int digits_count = 40);
    HugeInt(const HugeInt &temp, bool invert = false);
    HugeInt(long long n);

    void set(string str);
    bool is_zero();
    bool has_minus();
    string to_str();
    void remove_leading_zeros();

    HugeInt& operator=(const HugeInt &temp);
    HugeInt& operator=(const long long &temp);
    HugeInt& operator=(const string &str);

    friend istream& operator>>(istream &in, HugeInt &a);
    friend ifstream& operator>>(ifstream &in, HugeInt &a);

    friend ostream& operator<<(ostream &out, const HugeInt &a);
    friend ofstream& operator<<(ofstream &out, HugeInt &a);

    friend bool operator==(const HugeInt &a, const HugeInt &b);
    friend bool operator!=(const HugeInt &a, const HugeInt &b);

    friend bool operator>(const HugeInt&a, const HugeInt &b);
    friend bool operator>=(const HugeInt &a, const HugeInt &b);
 
    friend bool operator<(const HugeInt &a, const HugeInt &b);
    friend bool operator<=(const HugeInt &a, const HugeInt &b);

    // friend HugeInt operator+(const HugeInt &a, const HugeInt &b);
    // friend HugeInt operator-(const HugeInt &a, const HugeInt &b);
  
    const HugeInt operator-();

    friend HugeInt operator+(HugeInt a, const HugeInt &b);
    // friend HugeInt operator+(HugeInt &a, HugeInt &b);
	  friend HugeInt operator+(const HugeInt &a, long long value);
	  friend HugeInt operator+(long long value, const HugeInt &a);

    friend HugeInt operator-(HugeInt left, const HugeInt &right);
    // friend HugeInt operator-(HugeInt &a, HugeInt &b);
	  friend HugeInt operator-(const HugeInt &a, long long value);
	  friend HugeInt operator-(long long value, const HugeInt &a);
    

  private:
    vector<unsigned char> array;
    unsigned int digit_count;
    unsigned int capacity;
    bool minus = false;
};

bool operator==(const HugeInt &a, const HugeInt &b) {
  if (a.digit_count == b.digit_count && a.minus == b.minus) {
    for (int i = 0; i < a.digit_count; i++)
      if (a.array[i] != b.array[i]) return false;
    return true;
  } else return false;
}

bool operator<(const HugeInt &a, const HugeInt &b) {
  if (a.minus == b.minus) {
    if (a.minus) {
      // если оба отрицательные
      if (a.digit_count == b.digit_count) {
        // сравниваем каждую цифру
        for (int i = 0; i < a.digit_count; i++)
          if (a.array[i] == b.array[i]) continue;
          else return (a.array[i] > b.array[i]);
        return false;
      } else return (a.digit_count > b.digit_count);
    } else {
      // если оба положительные
      if (a.digit_count == b.digit_count) {
        for (int i = 0; i < a.digit_count; i++)
          if (a.array[i] == b.array[i]) continue;
          else return (a.array[i] < b.array[i]);
        return false;
        // сравниваем каждую цифру
      } else return (a.digit_count < b.digit_count);
    }
  } else return a.minus;
}

ostream& operator<<(ostream &out, const HugeInt &a) {
  if (a.minus) out << "-";
  for (int i = a.digit_count - 1; i > -1; i--)
    out << (char) (a.array[i] + '0');
  return out;
}

class complex {
  private:
    double re, im;
  public:
    complex(double re = 0, double im = 0) : re(re), im(im) {}
    friend ostream& operator<<(ostream& out, const complex& c) {
      out << "(" << c.re << "+" << c.im << "*i)";
    }
};