/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdbool.h>

#include "value.h"

bool is_char_delim(char c, char const *delim)
{
    for (unsigned int i = 0; delim[i] != END_STR; ++i) {
        if (c == delim[i]) {
            return true;
        }
    }
    return false;
}