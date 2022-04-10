#pragma once

#include <vector>
#include <string>
using namespace std;

class HugeInt {
  public:
    HugeInt(int digits = 40, string str = "0");
    void set(int n);
    int get(int n);
    void print();
    friend HugeInt operator+(const HugeInt &a, const HugeInt &b);
    friend HugeInt operator-(const HugeInt &a, const HugeInt &b);
    friend HugeInt operator*(const HugeInt &a, const HugeInt &b);
    friend HugeInt operator/(const HugeInt &a, const HugeInt &b);
  
  private:
    vector <unsigned char> array;
    unsigned int i = 0;
    unsigned int digits_count;
    bool minus = false;
};