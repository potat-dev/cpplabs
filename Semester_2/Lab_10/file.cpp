#include "file.h"

#include <fstream>
#include <sstream>

string read_file(const char *path) {
  ifstream file (path);
  stringstream stream;
  stream << file.rdbuf();
  return stream.str();
}