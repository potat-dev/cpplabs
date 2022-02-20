#pragma once

class HugeInt {
  public:
    void set(int n);
    int get(int n);
    void print();
  
  private:
    char arr[40] = {0};
    unsigned int i = 0;
};