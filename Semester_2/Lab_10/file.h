#pragma once

#include <string>
#include <iostream>

using namespace std;

string read_file(const char *path);
void read_file(const char *path, string &str);
void split_lines(string &str);
void write_file(string str, const char *path);