#pragma once

#include <string>

class Settings {
 public:
  std::string file_1, file_2;
  std::string file_out = "out.txt";
  bool interactive = false;
  bool verbose = false;
  bool use_column = false;
  size_t iters = 0;
};