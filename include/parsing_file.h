/*
**
** PARSING_FILE
** Rigolo2015, Yannis, 2022
** 
*/

#ifndef PROJECT_H_
#define PROJECT_H_

#include <stdbool.h>
#include <stddef.h>

int main(int ac, char const * const * av);
int start_project(char const * const * av);

#define FD_ERROR -100
#define FSTAT_ERROR -101
#define CLOSE_ERROR -102

#define DEBUG() printf("l.%d\n", __LINE__);
#define DEBUG_STR(x) printf("[%s]: l.%d\n", x, __LINE__);
#define DEBUG_NBR(x) printf("[%d]: l.%d\n", x, __LINE__);

#define STEP() printf("step ------------------%d\n", __LINE__);

#define BASIC_FLAG_OPEN 100

int open_file(char const *path, int flags);

char *read_file(int file_descriptor);

int get_size_file(int file_descriptor);

int close_file(int file_descriptor);

char *get_str_from_path(char const *path);

char **get_array_from_path(char const *path, char const *delim_points);

char **get_array_from_str(char const *str, char const *delim_points);

int replace_char_in_str(char *str, char old_char, char new_char);

int replace_char_in_array(char **array, char old_char, char new_char);

//? TOOLS

bool is_char_delim(char c, char const *delim);

int count_nb_word(char const *str, char const *delim);

size_t get_size_word(char const *str, char const *delim);

void get_word(char const *str, char *word, char const *delim, int *i);

#endif

//! GROS PROBLEME MAKEFILE JE N'UTILISE PAS OBJ DANS LE MAKE