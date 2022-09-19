#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "multiply.hpp"
#include "number.hpp"

using namespace std;

#define EXEC "multiplier.exe"
#define TITLE "\nBig Number Multiplier - v0.2"
#define FOOTER \
  "Created with <3 by Cyber Potato (Denis Churilov) at SUAI University"

double measure_time(int N, function<void()> func) {
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < N; i++) func();
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  return (double)duration.count() / N / 1000;  // ms
}

void interactive_mode(size_t iters,
                      Number (*multiply)(const Number &a, const Number &b)) {
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

void file_mode(string &file_1, string &file_2, string &file_out, size_t iters,
               Number (*multiply)(const Number &a, const Number &b)) {
  Number n1, n2, res;
  ifstream fin(file_1);
  string s;

  if (!fin.is_open()) {
    cout << "Error: cannot open file " << (file_1.length() ? file_1 : "1");
    return;
  } else {
    fin >> s;
    fin.close();
    cout << "Number 1 size: " << s.size() << endl;
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

int main(int argc, char **argv) {
  CLI::App app(TITLE, EXEC);
  app.footer(FOOTER);

  string file_1, file_2;
  string file_out = "out.txt";
  bool interactive = false;
  bool verbose = false;
  bool column = false;
  size_t iters = 0;

  app.add_option("file 1", file_1, "First file")->option_text("FILE");
  app.add_option("file 2", file_2, "Second file")->option_text("FILE");
  app.add_option("output", file_out, "Output file")->option_text("FILE");
  app.add_flag("-i, --interactive", interactive,
               "Interactive mode (manual input)");
  app.add_flag("-v, --verbose", verbose,
               "Verbose output (digits count, time stats, etc.)");
  app.add_flag("-c, --column", column, "Use column multiplication");
  app.add_option("-b, --benchmark", iters, "Benchmark mode (iterations count)")
      ->option_text("N");

  CLI11_PARSE(app, argc, argv);

  Number (*multiply)(const Number &, const Number &) =
      column ? column_multiply : fft_multiply;

  if (verbose) {
    cout << "File 1: " << file_1 << endl;
    cout << "File 2: " << file_2 << endl;
    cout << "Output: " << file_out << endl;
    cout << "Interactive: " << interactive << endl;
    cout << "Verbose: " << verbose << endl;
    cout << "Iterations: " << iters << endl;
    cout << (column ? "Using column multiplication" : "Using FFT multiplication");
    cout << endl;
  }

  if (interactive) {
    interactive_mode(iters, multiply);
  } else {
    file_mode(file_1, file_2, file_out, iters, multiply);
  }

  return 0;
}
