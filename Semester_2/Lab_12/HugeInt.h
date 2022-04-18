#pragma once

#include <vector>
#include <string>
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

    HugeInt& operator=(const HugeInt &temp);
    HugeInt& operator=(const long long &temp);
    HugeInt& operator=(const string &str);

    friend istream& operator>>(istream &in, HugeInt &a);
    friend ostream& operator<<(ostream &out, const HugeInt &a);

    friend bool operator==(const HugeInt &a, const HugeInt &b);
    friend bool operator!=(const HugeInt &a, const HugeInt &b);

    friend bool operator>(const HugeInt&a, const HugeInt &b);
    friend bool operator>=(const HugeInt &a, const HugeInt &b);
 
    friend bool operator<(const HugeInt &a, const HugeInt &b);
    friend bool operator<=(const HugeInt &a, const HugeInt &b);

    friend HugeInt operator+(const HugeInt &a, const HugeInt &b);
    friend HugeInt operator-(const HugeInt &a, const HugeInt &b);
  
    const HugeInt operator-();

  private:
    vector <unsigned char> array;
    unsigned int digit_count;
    unsigned int capacity;
    bool minus = false;
};