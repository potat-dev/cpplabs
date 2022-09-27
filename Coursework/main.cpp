#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "modes/modes.h"
#include "modes/settings.h"

using namespace std;

#define EXEC "multiplier.exe"
#define TITLE "\nBig Number Multiplier - v0.6 beta"
#define FOOTER \
  "Created with <3 by Cyber Potato (Denis Churilov) at SUAI University"

int main(int argc, char **argv) {
  // create CLI app
  CLI::App app(TITLE, EXEC);
  Settings config;
  app.footer(FOOTER);

  // input and output files
  app.add_option("file 1", config.file_1, "First file")->option_text("FILE");
  app.add_option("file 2", config.file_2, "Second file")->option_text("FILE");
  app.add_option("output", config.file_out, "Output file")->option_text("FILE");

  // flags
  app.add_flag("-i, --interactive", config.interactive,
               "Interactive mode (manual input)");
  app.add_flag("-v, --verbose", config.verbose,
               "Verbose output (digits count, time stats, etc.)");
  app.add_flag("-c, --column", config.use_column, "Use column multiplication");
  app.add_option("-b, --benchmark", config.iters,
                 "Benchmark mode (iterations count)")
      ->option_text("ITERS");

  // parse CLI arguments
  CLI11_PARSE(app, argc, argv);

  // check if no files or interactive mode specified
  if (config.file_1.empty() && config.file_2.empty() && !config.interactive) {
    cout << "No files or interactive mode specified" << endl;
    cout << "Use -h or --help to see usage" << endl;
    return 0;
  }

  // run selected mode
  try {
    (config.interactive ? interactive_mode : file_mode)(config);
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
    return 1;
  }
}
