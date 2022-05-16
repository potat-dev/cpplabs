#ifndef HUGEINT_H
#define HUGEINT_H

#include <string>
#include <iostream>

class HugeInt {
  private:
    int number[40];
    int depth;
    bool negative;
  
  public:
    HugeInt();
    HugeInt(int depth);
    HugeInt(int numbers[40], int depth);
  
    void set(std::string str);
    std::string get();
  
    bool check_zero();
    int compare(HugeInt &b);
    HugeInt simple_sum(HugeInt &b);
    HugeInt simple_dif(HugeInt &b);
    HugeInt sum(HugeInt &b);
    HugeInt dif(HugeInt &b);
};

#endif