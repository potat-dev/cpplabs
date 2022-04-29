#pragma once

#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class HugeInt {

  private:

    vector <unsigned char> array;
    unsigned int digit_count;
    bool minus = false;

  public:

    // конструкторы

    HugeInt(string str = "0");
    HugeInt(const HugeInt &temp, bool invert = false);
    HugeInt(long long n);

    // сеттеры / геттеры

    void set(string str);
    bool is_zero();
    bool has_minus();
    string to_str();
    void remove_leading_zeros();

    // операторы присваивания

    HugeInt& operator=(const HugeInt &temp);
    HugeInt& operator=(const long long &temp);
    HugeInt& operator=(const string &str);

    // операторы ввода / вывода

    friend istream& operator>>(istream &in, HugeInt &a);
    friend ifstream& operator>>(ifstream &in, HugeInt &a);

    friend ostream& operator<<(ostream &out, const HugeInt &a);
    friend ofstream& operator<<(ofstream &out, HugeInt &a);

    // операторы стравнения

    friend bool operator==(const HugeInt &a, const HugeInt &b);
    friend bool operator==(const HugeInt &a, long long b);
    friend bool operator==(long long a, const HugeInt &b);

    friend bool operator!=(const HugeInt &a, const HugeInt &b);
    friend bool operator!=(const HugeInt &a, long long b);
    friend bool operator!=(long long a, const HugeInt &b);

    friend bool operator>(const HugeInt&a, const HugeInt &b);
    friend bool operator>(const HugeInt &a, long long b);
    friend bool operator>(long long a, const HugeInt &b);

    friend bool operator>=(const HugeInt &a, const HugeInt &b);
    friend bool operator>=(const HugeInt &a, long long b);
    friend bool operator>=(long long a, const HugeInt &b);
 
    friend bool operator<(const HugeInt &a, const HugeInt &b);
    friend bool operator<(const HugeInt &a, long long b);
    friend bool operator<(long long a, const HugeInt &b);

    friend bool operator<=(const HugeInt &a, const HugeInt &b);
    friend bool operator<=(const HugeInt &a, long long b);
    friend bool operator<=(long long a, const HugeInt &b);

    // изменение знака

    HugeInt operator-() const;
    friend HugeInt habs(const HugeInt &value);

    // операторы сложения / вычитания

    friend HugeInt operator+(HugeInt a, const HugeInt &b);
	  friend HugeInt operator+(const HugeInt &a, long long value);
	  friend HugeInt operator+(long long value, const HugeInt &a);
    // friend HugeInt operator+(const HugeInt &a, const HugeInt &b);
    // friend HugeInt operator+(HugeInt &a, HugeInt &b);

    friend HugeInt operator-(HugeInt left, const HugeInt &right);
	  friend HugeInt operator-(const HugeInt &a, long long value);
	  friend HugeInt operator-(long long value, const HugeInt &a);
    // friend HugeInt operator-(const HugeInt &a, const HugeInt &b);
    // friend HugeInt operator-(HugeInt &a, HugeInt &b);

};