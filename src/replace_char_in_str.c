/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#include <stddef.h>

#include "parsing_file.h"
#include "value.h"

int replace_char_in_str(char *str, char old_char, char new_char)
{
    if (str == NULL) {
        return -1;
    }
    for (int i = 0; str[i] != END_STR; ++i) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
    return SUCCESS;
}
