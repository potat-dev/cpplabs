#pragma once

#include <functional>

#include "settings.h"

double measure_time(int N, std::function<void()> func);

void interactive_mode(const Settings &config);
void file_mode(const Settings &config);