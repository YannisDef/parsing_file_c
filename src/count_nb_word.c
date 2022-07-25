/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdbool.h>

#include "parsing_file.h"
#include "value.h"

int count_nb_word(char const *str, char const *delim)
{
    int nb_word = 0;
    bool c = false;
    bool x = false;

    for (unsigned int i = 0; str[i] != END_STR; ++i) {
        c = is_char_delim(str[i], delim);
        x = is_char_delim(str[i + 1], delim);
        if (c && !x) {
            ++nb_word;
        }
    }
    return nb_word;
}