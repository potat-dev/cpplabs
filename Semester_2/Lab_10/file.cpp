#include "file.h"

#include <fstream>
#include <sstream>

string read_file(const char *path) {
  ifstream file (path);
  stringstream stream;
  stream << file.rdbuf();
  file.close();
  return stream.str();
}

void read_file(const char *path, string &str) {
  str = read_file(path);
}

void split_lines(string &str) {
  for (int i = 0; i < str.length(); i += 60)
    str.insert(i, (i) ? "\n  " : "  ");
}

void write_file(string str, const char *path) {
  ofstream out("output.txt");
  out << str;
  out.close();
}