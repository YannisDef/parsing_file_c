/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "parsing_file.h"
#include "value.h"

int get_array_from_path(char const *path, char const *delim_points, char ***array)
{
    char *buffer = NULL;
    int close_value = 0;
    int file_descriptor = open_file(path, BASIC_FLAG_OPEN);

    if (file_descriptor == FD_ERROR) {
        return FD_ERROR;
    }
    buffer = read_file(file_descriptor);
    if (buffer == NULL) {
        return READ_ERROR;
    }
    close_value = close_file(file_descriptor);
    if (close_value == CLOSE_ERROR) {
        return CLOSE_ERROR;
    }
    (*array) = get_array_from_str(buffer, delim_points);
    free(buffer);
    if (array == NULL) {
        return ARRAY_F_STR_ERROR;
    }
    return SUCCESS;
}