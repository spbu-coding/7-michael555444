#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static const int PAR_C = 1;
static const int F_NAME = 1;
static const int SUCCESS = 0;
static const int UNSUCCESS = -1;

typedef size_t count_of_strings_t;
typedef int parameters_count_t;
typedef char *string_t, *file_name_t;
typedef char **parameters_t;

int par_check(parameters_count_t parameters_count, parameters_t parameters);
