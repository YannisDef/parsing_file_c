/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <unistd.h>
#include <sys/stat.h>

#include "parsing_file.h"
#include "value.h"

//TODO A changer en return INT

char *get_str_from_path(char const *path)
{
    char *buffer = NULL;
    int close_value = 0;
    int file_descriptor = open_file(path, BASIC_FLAG_OPEN);

    if (file_descriptor == FD_ERROR) {
        return NULL;
    }
    buffer = read_file(file_descriptor);
    if (buffer == NULL) {
        return NULL;
    }
    close_value = close_file(file_descriptor);
    if (close_value == CLOSE_ERROR) {
        return NULL;
    }
    return buffer;
}