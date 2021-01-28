#include <stdio.h>

#define error(...) fprintf(stderr, __VA_ARGS__)

static const char *DELETE = ",.;:!?\n";

void bubble() {
    for (array_size_t i = 0; i < array_size; i++)
        for (array_size_t j = i + 1; j < array_size; j++)
            if (comparator(strings_array[i], strings_array[j]) > 0) {
                char *swapper = strings_array[i];
                strings_array[i] = strings_array[j];
                strings_array[j] = swapper;
            }
}

int main(int argc, char *argv[]){
    if (argc == 2; argv[2] ){

    }
    else error(Invalid args);
    return 1;
}