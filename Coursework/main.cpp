#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "modes.hpp"
#include "settings.hpp"

using namespace std;

#define EXEC "multiplier.exe"
#define TITLE "\nBig Number Multiplier - v0.5 beta"
#define FOOTER \
  "Created with <3 by Cyber Potato (Denis Churilov) at SUAI University"

int main(int argc, char **argv) {
  CLI::App app(TITLE, EXEC);
  Settings settings;
  app.footer(FOOTER);

  app.add_option("file 1", settings.file_1, "First file")->option_text("FILE");
  app.add_option("file 2", settings.file_2, "Second file")->option_text("FILE");
  app.add_option("output", settings.file_out, "Output file")
      ->option_text("FILE");
  app.add_flag("-i, --interactive", settings.interactive,
               "Interactive mode (manual input)");
  app.add_flag("-v, --verbose", settings.verbose,
               "Verbose output (digits count, time stats, etc.)");
  app.add_flag("-c, --column", settings.use_column,
               "Use column multiplication");
  app.add_option("-b, --benchmark", settings.iters,
                 "Benchmark mode (iterations count)")
      ->option_text("N");

  CLI11_PARSE(app, argc, argv);

  if (settings.file_1.empty() && settings.file_2.empty() &&
      !settings.interactive) {
    cout << "No files or interactive mode specified" << endl;
    cout << "Use -h or --help to see usage" << endl;
    return 0;
  }

  if (settings.verbose) {
    cout << "Verbode info:" << endl;
    cout << "File 1: " << settings.file_1 << endl;
    cout << "File 2: " << settings.file_2 << endl;
    cout << "Output: " << settings.file_out << endl;
    cout << "Interactive: " << settings.interactive << endl;
    cout << "Iterations: " << settings.iters << endl;
    cout << (settings.use_column ? "Using column multiplication"
                                 : "Using FFT multiplication");
    cout << endl;
  }

  void (*mode)(const Settings &) =
      settings.interactive ? interactive_mode : file_mode;

  mode(settings);
}
