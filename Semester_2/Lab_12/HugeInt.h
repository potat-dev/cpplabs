#pragma once

#include <vector>
#include <string>
using namespace std;

class HugeInt {
  public:
    HugeInt(string str = "0", int digits_count = 40);
    HugeInt(long long n);
    HugeInt(const HugeInt &temp, bool invert = false);
    // ~HugeInt(); не нужен

    void print();
    bool is_zero();

    friend bool operator==(const HugeInt &a, const HugeInt &b);
    friend bool operator!=(const HugeInt &a, const HugeInt &b);

    friend bool operator>(const HugeInt&a, const HugeInt &b);
    friend bool operator>=(const HugeInt &a, const HugeInt &b);
 
    friend bool operator<(const HugeInt &a, const HugeInt &b);
    friend bool operator<=(const HugeInt &a, const HugeInt &b);

    friend HugeInt operator+(const HugeInt &a, const HugeInt &b);
    friend HugeInt operator-(const HugeInt &a, const HugeInt &b);
  
  private:
    vector <unsigned char> array;
    unsigned int digit_count;
    unsigned int capacity;
    bool minus = false;
};