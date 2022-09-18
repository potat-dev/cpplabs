#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "fft.hpp"

using namespace std;

#define EXEC "multiplier.exe"
#define TITLE "\nBig Number Multiplier - v0.2"
#define FOOTER \
  "Created with <3 by Cyber Potato (Denis Churilov) at SUAI University"

int main(int argc, char** argv) {
  CLI::App app(TITLE, EXEC);
  app.footer(FOOTER);

  string file_1, file_2;
  string file_out = "out.txt";
  bool interactive = false;
  bool verbose = false;
  size_t iters = 1;

  app.add_option("file 1", file_1, "First file")->option_text("FILE");
  app.add_option("file 2", file_2, "Second file")->option_text("FILE");
  app.add_option("output", file_out, "Output file")->option_text("FILE");
  app.add_flag("-i, --interactive", interactive,
               "Interactive mode (manual input)");
  app.add_flag("-v, --verbose", verbose,
               "Verbose output (digits count, time stats, etc.)");
  app.add_option("-b, --benchmark", iters, "Benchmark mode (iterations count)")
      ->option_text("N");
  // app.add_option("-n, --iters", iters, "Number of iterations (for
  // benchmark)")
  // ->option_text("N");

  CLI11_PARSE(app, argc, argv);

  cout << "File 1: " << file_1 << endl;
  cout << "File 2: " << file_2 << endl;
  cout << "Output: " << file_out << endl;
  cout << "Interactive: " << interactive << endl;
  cout << "Verbose: " << verbose << endl;
  cout << "Iterations: " << iters << endl;

  if (verbose) cout << "Verbose output is not implemented yet" << endl;

  if (interactive) {
    cout << "Interactive mode is not implemented yet" << endl;
  } else {
    string s;
    
    ifstream fin(file_1);
    fin >> s;
    fin.close();
    cout << "Number 1 size: " << s.size() << endl;
    Number n1(s);

    fin.open(file_2);
    fin >> s;
    fin.close();
    cout << "Number 2 size: " << s.size() << endl;
    Number n2(s);

    Number result = n1.fft_multiply(n2);

    ofstream fout(file_out);
    cout << "Result size: " << result.size() << endl;
    fout << result;
  }

  return 0;
}

/*
  // Number n1, n2, result;
  cout << "Reading files..." << endl;
  string s;
  ifstream fin(file_1);
  if (!fin) {  // check if file exists
    cout << "File " << (file_1.length() ? file_1 : "1") << " does not exist";
    return 1;
  }
  fin >> s;
  fin.close();
  Number n1(s);
  cout << "Number 1 size: " << s.size() << endl;
  fin.open(file_2);
  if (!fin) {  // check if file exists
    cout << "File " << (file_2.length() ? file_2 : "2") << " does not exist";
    return 1;
  }
  fin >> s;
  fin.close();
  Number n2(s);
  cout << "Number 2 size: " << s.size() << endl;
  Number result(0);
  if (iters > 1) {
  // time measurement
  auto start = chrono::high_resolution_clock::now();
  for (size_t i = 0; i < iters; i++) {
    result = n1.fft_multiply(n2);
  }
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by function: " << duration.count() / iters <<
  "microseconds"
           << endl;
    } else {
      result = n1.fft_multiply(n2);
    }
    ofstream fout(file_out);
    cout << "Result size: " << result.size() << endl;
    fout << result;
*/