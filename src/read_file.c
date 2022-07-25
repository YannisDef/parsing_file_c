/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#include "parsing_file.h"
#include "value.h"

char *read_file(int file_descriptor)
{
    char *buffer = NULL;
    int nbytes_readed = 0;
    int nbytes_to_read = get_size_file(file_descriptor);

    if (nbytes_readed == FSTAT_ERROR) {
        return NULL;
    }
    buffer = malloc(sizeof(char) * (nbytes_to_read + 1));
    nbytes_readed = read(file_descriptor, buffer, nbytes_to_read);
    if (nbytes_readed == -1) {
        perror("read");
        return NULL;
    }
    buffer[nbytes_readed] = END_STR;
    return buffer;
}