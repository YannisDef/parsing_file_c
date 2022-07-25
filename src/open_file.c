/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

#include "parsing_file.h"
#include "value.h"

int open_file(char const *path, int flags)
{
    int fd = 0;

    if (flags == BASIC_FLAG_OPEN) {
        flags = O_RDONLY;
    }
    fd = open(path, flags);
    if (fd == -1) {
        perror("open");
        return FD_ERROR;
    }
    return fd;
}