#pragma once

#include "confirm.h"


static const char SEPS[] = {'.', ',', ';', ':', '!', '?'};
static const int STR_LEN = 1000 + 1;
static const int STR_C = 100;
static const int SEPS_C = sizeof(SEPS) / sizeof(char);

typedef char **strings_array_t;
typedef size_t array_size_t;

int strings_c(file_name_t);

void input(file_name_t, array_size_t, strings_array_t);

void bubble(strings_array_t, size_t);

void seps(strings_array_t, array_size_t);