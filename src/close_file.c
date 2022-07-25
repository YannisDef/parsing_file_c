/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <unistd.h>
#include <stdio.h>

#include "parsing_file.h"
#include "value.h"

int close_file(int file_descriptor)
{
    int r_value = close(file_descriptor);

    if (r_value == -1) {
        perror("close");
        return CLOSE_ERROR;
    }
    return SUCCESS;
}

