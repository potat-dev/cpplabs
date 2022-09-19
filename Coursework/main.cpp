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

  if (verbose) {
    cout << "File 1: " << file_1 << endl;
    cout << "File 2: " << file_2 << endl;
    cout << "Output: " << file_out << endl;
    cout << "Interactive: " << interactive << endl;
    cout << "Verbose: " << verbose << endl;
    cout << "Iterations: " << iters << endl;
  }

  if (verbose) cout << "Verbose output is not implemented yet" << endl;

  if (interactive) {
    cout << "Interactive mode is not implemented yet" << endl;
  } else {
    Number n1, n2, res;
    string s;

    ifstream fin(file_1);
    if (!fin.is_open()) {
      cout << "Error: cannot open file " << (file_1.length() ? file_1 : "1");
      return 1;
    }

    fin >> s;
    fin.close();
    cout << "Number 1 size: " << s.size() << endl;
    n1.set(s);

    fin.open(file_2);
    if (!fin.is_open()) {
      cout << "Error: cannot open file " << (file_2.length() ? file_2 : "1");
      return 1;
    }

    fin >> s;
    fin.close();
    cout << "Number 2 size: " << s.size() << endl;
    n2.set(s);

    if (iters > 1) {
      // measure time
      auto start = chrono::high_resolution_clock::now();
      for (size_t i = 0; i < iters; i++) {
        res = n1.fft_multiply(n2);
      }
      auto end = chrono::high_resolution_clock::now();
      auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
      cout << "Time: " << (double)duration.count() / iters / 1000
           << " ms / iter" << endl;
    } else {
      res = n1.fft_multiply(n2);
    }

    ofstream fout(file_out);
    cout << "Result size: " << res.size() << endl;
    fout << res;
  }

  return 0;
}
