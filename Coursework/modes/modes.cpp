#include "modes.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <string>

#include "../number/number.h"
#include "settings.h"

using namespace std;

double measure_time(int N, function<void()> func) {
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < N; i++) func();
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  return (double)duration.count() / N / 1000;  // ms
}

// --- Interactive mode --- //

void interactive_mode(const Settings &config) {
  Number n1, n2, res;

  cout << "Enter two big numbers to multiply them" << endl;
  cout << "Press Ctrl + C to exit" << endl;

  if (config.iters) {
    cout << "Each operation will be repeated ";
    cout << config.iters << " times" << endl;
  }

  Number (*mult)(const Number &, const Number &) =
      config.use_column ? column_multiply : fft_multiply;

  while (true) {
    try {
      cout << "\nEnter first number:\n> ";
      cin >> n1;
      if (config.verbose) cout << "Digits count: " << n1.size() << endl;
    } catch (const exception &e) {
      cout << "Invalid number" << endl;
      continue;
    }

    try {
      cout << "\nEnter second number:\n> ";
      cin >> n2;
      if (config.verbose) cout << "Digits count: " << n2.size() << endl;
    } catch (const exception &e) {
      cout << "Invalid number" << endl;
      continue;
    }

    if (config.iters) {
      double time = measure_time(config.iters, [&]() { res = mult(n1, n2); });
      cout << "Average time: " << time << " ms / iter" << endl;
    } else {
      res = mult(n1, n2);
    }

    cout << "\nResult:\n> " << res << endl;
    if (config.verbose) cout << "Digits count: " << res.size() << endl;
  }
}

// --- File mode --- //

void file_mode(const Settings &config) {
  Number n1, n2, res;

  try {
    n1.load(config.file_1);
    if (config.verbose) cout << "Number 1 size: " << n1.size() << endl;
  } catch (const exception &e) {
    cout << "Error: cannot load number from file "
         << (config.file_1.length() ? config.file_1 : "1");
    return;
  }

  try {
    n2.load(config.file_2);
    if (config.verbose) cout << "Number 2 size: " << n2.size() << endl;
  } catch (const exception &e) {
    cout << "Error: cannot load number from file "
         << (config.file_2.length() ? config.file_2 : "2");
    return;
  }

  Number (*mult)(const Number &, const Number &) =
      config.use_column ? column_multiply : fft_multiply;

  if (config.iters) {
    double time = measure_time(config.iters, [&]() { res = mult(n1, n2); });
    cout << "Average time: " << time << " ms / iter" << endl;
  } else {
    res = mult(n1, n2);
  }

  if (config.verbose) cout << "Result size: " << res.size() << endl;
  res.save(config.file_out);
}