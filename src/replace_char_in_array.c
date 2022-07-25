/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stddef.h>

#include "parsing_file.h"
#include "value.h"

int replace_char_in_array(char **array, char old_char, char new_char)
{
    if (array == NULL) {
        return -1;
    }
    for (int i = 0; array[i] != END_ARRAY; ++i) {
        for (int j = 0; array[i][j] != END_STR; ++j) {
            if (array[i][j] == old_char) {
                array[i][j] = new_char;
            }
        }
    }
    return SUCCESS;
}
