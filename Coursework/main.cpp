#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "modes.hpp"

using namespace std;

#define EXEC "multiplier.exe"
#define TITLE "\nBig Number Multiplier - v0.4"
#define FOOTER \
  "Created with <3 by Cyber Potato (Denis Churilov) at SUAI University"

int main(int argc, char **argv) {
  CLI::App app(TITLE, EXEC);
  app.footer(FOOTER);

  string file_1, file_2;
  string file_out = "out.txt";
  bool interactive = false;
  bool verbose = false;
  bool use_column = false;
  size_t iters = 0;

  app.add_option("file 1", file_1, "First file")->option_text("FILE");
  app.add_option("file 2", file_2, "Second file")->option_text("FILE");
  app.add_option("output", file_out, "Output file")->option_text("FILE");
  app.add_flag("-i, --interactive", interactive,
               "Interactive mode (manual input)");
  app.add_flag("-v, --verbose", verbose,
               "Verbose output (digits count, time stats, etc.)");
  app.add_flag("-c, --column", use_column, "Use column multiplication");
  app.add_option("-b, --benchmark", iters, "Benchmark mode (iterations count)")
      ->option_text("N");

  CLI11_PARSE(app, argc, argv);

  if (verbose) {
    cout << "File 1: " << file_1 << endl;
    cout << "File 2: " << file_2 << endl;
    cout << "Output: " << file_out << endl;
    cout << "Interactive: " << interactive << endl;
    cout << "Verbose: " << verbose << endl;
    cout << "Iterations: " << iters << endl;
    cout << (use_column ? "Using column multiplication"
                        : "Using FFT multiplication");
    cout << endl;
  }

  if (interactive) {
    interactive_mode(iters, use_column);
  } else {
    file_mode(file_1, file_2, file_out, iters, use_column);
  }

  return 0;
}
