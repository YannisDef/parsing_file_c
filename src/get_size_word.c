/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdio.h>

#include "parsing_file.h"
#include "value.h"

size_t get_size_word(char const *str, char const *delim)
{
    size_t size = 0;

    while (str[size] != END_STR && !is_char_delim(str[size], delim)) {
        ++size;
    }
    return size;
}