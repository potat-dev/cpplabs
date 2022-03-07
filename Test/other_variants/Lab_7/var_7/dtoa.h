#pragma once

char* dtoa(double num, int npos, int nfr);
int before_decimal(double d);
int after_decimal(double d);
int digits_count(double d);
int double_length(double d);

char* to_char_array(double num_double, int decimal_place);