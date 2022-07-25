/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "parsing_file.h"
#include "value.h"

char **get_array_from_str(char const *str, char const *delim_points)
{
    int nb_word = 0;
    char **array = NULL;
    int index = 0;
    int size = 0;

    for (int i = 0; str[i] != END_STR; ++i) {
        array = realloc(array, sizeof(char *) * (index + 1));
        array[index] = malloc(sizeof(char) * (get_size_word(str + i, delim_points) + 1));
        get_word(str + i, array[index], delim_points, &i);
        for (; is_char_delim(str[i], delim_points) AND str[i] != END_STR; ++i);
        ++index;
        --i;
    }
    array = realloc(array, sizeof(char *) * (index + 1));
    array[index] = NULL;
    return array;
}
