/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdio.h>
#include <stdlib.h>

#include "parsing_file.h"

int main(int ac, char const * const *av)
{
    (void)ac;
    (void)av;
    printf("------------------------------------ START ------------------------------------\n\n");
    int fd = open_file("test_file.txt", BASIC_FLAG_OPEN);
    printf("fd = %d\n", fd);
    STEP();

    char *str = read_file(fd);
    printf("str = [%s]\n", str);
    STEP();


    int r_value_close_file = close_file(fd);
    printf("r_value_close_file = %d\n", r_value_close_file);
    STEP();

    char *str_from_path = get_str_from_path("test_file.txt");
    printf("str_from_path = [%s]\n", str_from_path);
    STEP();

    char **array_from_path = get_array_from_path("test_file.txt", "\n;");
    STEP();

    for (int i = 0; array_from_path[i] != NULL; ++i) {
        printf("array[%d] |%s|\n", i, array_from_path[i]);
        free(array_from_path[i]);
    }
    return 0;
}
