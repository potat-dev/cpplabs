#ifndef HUGEINT_H
#define HUGEINT_H

#include <string>
#include <iostream>

class HugeInt {
  private:
    int number[40];
    int depth;
    bool negative;

    int compare(HugeInt &b) const;
    HugeInt simple_sum(HugeInt &b);
    HugeInt simple_dif(HugeInt &b);
    HugeInt sum(HugeInt &b);
    HugeInt dif(HugeInt &b);

  public:
    HugeInt(); // конструктор по умолчанию
    HugeInt(int depth);
    HugeInt(int numbers[40], int depth);

    void set(std::string str); // set для массива цифр
    void set(int numbers[40]); // set для массива цифр
    std::string to_str() const;   // get для массива цифр

    void set_minus(bool state); // set для знака
    bool has_minus() const;     // get для знака
    void set_depth(int dep);    // set для длины числа
    int get_depth() const;      // get для длины числа

    void set_digit(int index, int digit); // set для разряда числа
    int get_digit(int index) const;       // get для разряда числа

    friend bool operator== (HugeInt &n1, HugeInt &n2);
    friend bool operator!= (HugeInt &n1, HugeInt &n2);

    friend bool operator> (HugeInt &d1, HugeInt &d2);
    friend bool operator<= (HugeInt &d1, HugeInt &d2);
 
    friend bool operator< (HugeInt &n1, HugeInt &n2);
    friend bool operator>= (HugeInt &n1, HugeInt &n2);

    friend HugeInt operator+(HugeInt &n1, HugeInt &n2);
    friend HugeInt operator-(HugeInt &n1, HugeInt &n2);

    bool check_zero() const;

    // операторы
    HugeInt operator-() const;

    void shrink_to_fit(); // обрезаем ненужные нули

    friend std::ostream& operator<<(std::ostream &out, const HugeInt &n);
    friend std::istream& operator>>(std::istream &in, HugeInt &n);
    //?  тест
    void print_full(); //?  print для теста
    void print();      //?  print для теста
};

#endif