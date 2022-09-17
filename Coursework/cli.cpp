#include <CLI/CLI.hpp>
#include <iostream>
#include <string>
using namespace std;

#define TITLE  "\nBig Number Multiplier - v0.1\n"
#define FOOTER "Created with <3 by Cyber Potato (Denis Churilov) at SUAI University"
#define EXEC   "multiplier.exe"

int main(int argc, char** argv) {
    CLI::App app(TITLE, EXEC);
    app.footer(FOOTER);

    string file_1, file_2;
    string file_out = "out.txt";
    bool interactive = false;
    bool verbose = false;

    app.add_option("file 1", file_1, "First file")->option_text("FILE");
    app.add_option("file 2", file_2, "Second file")->option_text("FILE");
    app.add_option("output", file_out, "Output file")->option_text("FILE");
    app.add_flag("-i, --interactive", interactive, "Interactive mode");
    app.add_flag("-v, --verbose", verbose, "Verbose output");

    CLI11_PARSE(app, argc, argv);
    
    cout << "File 1: " << file_1 << endl;
    cout << "File 2: " << file_2 << endl;
    cout << "Output: " << file_out << endl;
    cout << "Interactive: " << interactive << endl;
    cout << "Verbose: " << verbose << endl;
    return 0;
}