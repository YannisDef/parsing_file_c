/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

#include "parsing_file.h"
#include "value.h"

int get_size_file(int file_descriptor)
{
    struct stat statbuf = {0};
    int return_value = 0;

    return_value = fstat(file_descriptor, &statbuf);
    if (return_value == -1) {
        perror("fstat");
        return FSTAT_ERROR;
    }
    return statbuf.st_size;
}

