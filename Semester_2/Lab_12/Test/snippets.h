#pragma once

#include <string>
using namespace std;

class HugeInt {
  private:
    int arr[5];
    int test;

  public:
    string str = "hello";
    int arr_2[5];
    int pub = 42;
    void print();
    void set(int *a);
};

class Test {
  public:
    int arr[5];
    int test = 42;
    void print();
};