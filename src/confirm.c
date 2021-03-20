#include "confirm.h"
#define error(...) fprintf(stderr, __VA_ARGS__)


int err(char *text) {

    error("%s\n", text);
    return UNSUCCESS;

}

bool input_check(file_name_t file_name) {

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {

        return false;

    }

    fclose(file);
    return true;

}

bool count_check(parameters_count_t parameters_count) {

    if (parameters_count == PAR_C) {

        return true;

    }

    return false;

}

int par_check(parameters_count_t parameters_count, parameters_t parameters) {

    if (!count_check(parameters_count)) {

        return err("Input correct count of parameters.");

    }

    if (!input_check(parameters[F_NAME])) {

        return err("Input correct file name.");

    }

    return SUCCESS;

}