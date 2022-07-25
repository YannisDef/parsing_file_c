/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdio.h>

#include "parsing_file.h"
#include "value.h"

void get_word(char const *word, char *emplacement, char const *delim, int *i)
{
    size_t size = get_size_word(word, delim);
    int j = 0;

    while (size > 0) {
        emplacement[j] = word[j];
        ++*i;
        ++j;
        --size;
    }
    emplacement[j] = END_STR;
}
