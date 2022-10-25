#pragma once

#include <iostream>
#include <string>

std::string read_file(const char *path);
void read_file(const char *path, std::string &str);
void split_lines(std::string &str);
void write_file(std::string str, const char *path);