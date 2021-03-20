#include "confirm.h"
#include "handler.h"


int main(int argc, char *argv[]) {

    int exit = par_check(argc - 1, argv);
    int count = strings_c(argv[F_NAME]);
    char **str_arr = malloc(sizeof(char *) * count);
    for (int i = 0; i < count; i++) {

        str_arr[i] = malloc(sizeof(char) * STR_LEN);

    }

    input(argv[F_NAME], count, str_arr);
    seps(str_arr, count);
    bubble(str_arr, count);
    int cnt = count > 100 ? 100 : count;

    if (exit == UNSUCCESS) {

        return exit;

    }

    for (int i = 0; i < cnt; i++) {

        printf("%s", str_arr[i]);
        free(str_arr[i]);

    }

    free(str_arr);
    return exit;

}