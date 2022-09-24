#pragma once

#include <chrono>
#include <functional>
#include <iostream>
#include <string>

#include "number/number.h"
#include "settings.hpp"

using namespace std;

double measure_time(int N, function<void()> func) {
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < N; i++) func();
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  return (double)duration.count() / N / 1000;  // ms
}

void interactive_mode(const Settings &settings) {
  size_t iters = settings.iters;
  bool use_column = settings.use_column;
  Number (*multiply)(const Number &, const Number &) =
      use_column ? column_multiply : fft_multiply;
  cout << "Enter two big numbers to multiply them" << endl;
  cout << "Enter 'exit' to exit" << endl;
  if (iters) {
    cout << "Each operation will be repeated " << iters << " times" << endl;
  }
  cout << endl;

  string a, b;
  while (true) {
    cout << "Enter first number: ";
    cin >> a;
    if (a == "exit") break;
    cout << "Enter second number: ";
    cin >> b;
    if (b == "exit") break;

    Number num_a(a);
    Number num_b(b);
    Number result;

    if (iters) {
      double time =
          measure_time(iters, [&]() { result = multiply(num_a, num_b); });
      cout << "Result: " << result << endl;
      cout << "Time: " << time << " ms" << endl;
    } else {
      result = multiply(num_a, num_b);
      cout << "Result: " << result << endl;
    }
    cout << endl;
  }
}

void file_mode(const Settings &settings) {
  string file_1 = settings.file_1;
  string file_2 = settings.file_2;
  string file_out = settings.file_out;
  size_t iters = settings.iters;
  bool use_column = settings.use_column;
  Number (*multiply)(const Number &, const Number &) =
      use_column ? column_multiply : fft_multiply;
  Number n1, n2, res;
  ifstream fin(file_1);
  string s;

  if (!fin.is_open()) {
    cout << "Error: cannot open file " << (file_1.length() ? file_1 : "1");
    return;
  } else {
    fin >> s;
    fin.close();
    cout << "Number 1 size: " << s.size()
         << endl;  // TODO: print only if verbose
    n1.set(s);
  }

  fin.open(file_2);
  if (!fin.is_open()) {
    cout << "Error: cannot open file " << (file_2.length() ? file_2 : "2");
    return;
  } else {
    fin >> s;
    fin.close();
    cout << "Number 2 size: " << s.size() << endl;
    n2.set(s);
  }

  if (iters) {
    double time = measure_time(iters, [&]() { res = multiply(n1, n2); });
    cout << "Average time: " << time << " ms" << endl;
  } else {
    res = multiply(n1, n2);
  }

  ofstream fout(file_out);
  cout << "Result size: " << res.size() << endl;
  fout << res;
}