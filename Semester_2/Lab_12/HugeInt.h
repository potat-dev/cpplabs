#pragma once

#include <vector>
#include <string>
using namespace std;

class HugeInt {
  public:
    HugeInt(string str = "0", int digits_count = 40);
    void print();

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