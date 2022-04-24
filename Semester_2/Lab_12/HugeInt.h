#pragma once

#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

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

    friend ostream& operator<<(ostream &out, HugeInt &a);
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
    vector <unsigned char> array;
    unsigned int digit_count;
    unsigned int capacity;
    bool minus = false;
};