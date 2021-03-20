#include "handler.h"


int strings_c(file_name_t file_name) {

    FILE *input_file = fopen(file_name, "r");
    int count_of_input_strings = 0;
    char *input_string = malloc(sizeof(char) * STR_LEN);

    while (!feof(input_file)) {

        if (fgets(input_string, STR_LEN, input_file) != NULL) {

            count_of_input_strings++;

        }
    }

    free(input_string);
    fclose(input_file);

    return count_of_input_strings;

}

void input(file_name_t file_name, array_size_t array_size, strings_array_t strings_array) {

    FILE *input_file = fopen(file_name, "r");

    for (array_size_t i = 0; i < array_size; i++) {

        strings_array[i] = malloc(sizeof(char) * STR_LEN);
        fgets(strings_array[i], STR_LEN, input_file);

    }

    fclose(input_file);

}

void bubble(strings_array_t strings_array, array_size_t array_size) {

    for (array_size_t i = 0; i < array_size; i++) {

        for (array_size_t j = i + 1; j < array_size; j++) {

            if (strcmp(strings_array[i], strings_array[j]) < 0) {

                char *swapper = strings_array[i];
                strings_array[i] = strings_array[j];
                strings_array[j] = swapper;

            }
        }
    }
}

bool check(char symbol, const char *char_array, int array_size) {

    for (int i = 0; i < array_size; i++) {

        if (symbol == char_array[i]) {

            return true;

        }
    }

    return false;

}

void seps(strings_array_t strings_array, array_size_t array_size) {

    strings_array_t buffer = malloc(sizeof(char *) * array_size);

    for (int i = 0; i < array_size; i++) {

        buffer[i] = malloc(sizeof(char) * STR_LEN);

    }

    for (int i = 0; i < array_size; i++) {

        char *string = malloc(sizeof(char) * STR_LEN);
        int position = 0;

        for (int j = 0; j < strlen(strings_array[i]); j++) {

            if (!check(strings_array[i][j], SEPS, SEPS_C)) {

                string[position++] = strings_array[i][j];

            }
        }

        strcpy(buffer[i], string);

    }

    for (int i = 0; i < array_size; i++) {

        strcpy(strings_array[i], buffer[i]);

    }

    for (int i = 0; i < array_size; i++) {

        free(buffer[i]);

    }

    free(buffer);

}
