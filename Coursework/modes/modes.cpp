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
  return (double)duration.count() / N / 1000;  // return in milliseconds
}

// --- Interactive mode --- //

void interactive_mode(const Settings &config) {
  cout << "Enter two big nsumbers to multiply them" << endl;
  cout << "Press Ctrl + C or leave input empty to exit" << endl;

  if (config.iters) {
    cout << endl << "[i] Each operation will be repeated ";
    cout << config.iters << " times" << endl;
  }

  string buf;
  size_t iter = 0;
  double time = 0;
  Number n1, n2, res;

  Number (*mult)(const Number &, const Number &) =
      config.use_column ? column_multiply : fft_multiply;

  while (true) {
    signal(SIGINT, [](int) { /* empty handler */ });

    iter++;
    cout << endl << "Enter first number:" << endl << "[" << iter << "] > ";
    getline(cin, buf);
    if (cin.fail() || buf.empty() || buf == "q") break;

    try {
      n1.set(buf);
      if (config.verbose) cout << "[i] Digits count: " << n1.size() << endl;
    } catch (const invalid_argument &e) {
      cout << "[x] Invalid number" << endl;
      continue;
    }

    cout << endl << "Enter second number:" << endl << "[" << iter << "] > ";
    getline(cin, buf);
    if (cin.fail() || buf.empty() || buf == "q") break;

    try {
      n2.set(buf);
      if (config.verbose) cout << "[i] Digits count: " << n2.size() << endl;
    } catch (const invalid_argument &e) {
      cout << "[x] Invalid number" << endl;
      continue;
    }

    signal(SIGINT, [](int s) {  // interrupt too long operations
      cout << endl << "[x] Operation interrupted" << endl;
      exit(s);
    });

    if (config.iters) {
      time = measure_time(config.iters, [&]() { res = mult(n1, n2); });
    } else {
      res = mult(n1, n2);
    }

    cout << endl << "Result:" << endl << "[" << iter << "] > " << res << endl;
    if (config.verbose) cout << "[i] Digits count: " << res.size() << endl;
    if (config.iters)
      cout << endl << "[i] Average time: " << time << " ms / iter" << endl;
  }

  if (cin.fail()) cout << endl;
  cout << endl << "Bye! Have a nice day :)" << endl;
}

// --- File mode --- //

void file_mode(const Settings &config) {
  signal(SIGINT, [](int s) {
    cout << endl << "Bye! Have a nice day :)" << endl;
    exit(s);
  });

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

  if (config.verbose) cout << endl;
  cout << "Multiplying... (press Ctrl + C to interrupt)" << endl;

  if (config.iters) {
    double time = measure_time(config.iters, [&]() { res = mult(n1, n2); });
    if (config.verbose) cout << endl << "Result size: " << res.size();
    cout << endl << "Average time: " << time << " ms / iter" << endl;
  } else {
    res = mult(n1, n2);
    if (config.verbose) cout << endl << "Result size: " << res.size() << endl;
  }

  res.save(config.file_out);
  if (config.verbose) cout << "Result saved to " << config.file_out << endl;
}