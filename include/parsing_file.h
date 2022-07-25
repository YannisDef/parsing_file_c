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
#define READ_ERROR -103
#define ARRAY_F_STR_ERROR -104

#define DEBUG() printf("l.%d\n", __LINE__);
#define DEBUG_STR(x) printf("[%s]: l.%d\n", x, __LINE__);
#define DEBUG_NBR(x) printf("[%d]: l.%d\n", x, __LINE__);

#define STEP() printf("step ------------------%d\n", __LINE__);

#define BASIC_FLAG_OPEN 100

/**
 * @brief Open a file and return the file descriptor
 * 
 * @param path of the file
 * @param flags for the open function, if you send BASIC_FLAG_OPEN, it will be set to O_RDONLY
 * @return int fd of the file, FD_ERROR if an error occured
 */
int open_file(char const *path, int flags);

/**
 * @brief Read a file and return the content in a buffer (char *)
 * 
 * @param file_descriptor of the file
 * @return char * buffer of the file, NULL if an error occured
 */
char *read_file(int file_descriptor);

/**
 * @brief Get the size of the file
 * 
 * @param file_descriptor of the file
 * @return int size of the file, FSTAT_ERROR if an error occured
 */
int get_size_file(int file_descriptor);

/**
 * @brief Close a file
 * 
 * @param file_descriptor of the file
 * @return int SUCCESS if the file was closed, CLOSE_ERROR if an error occured
 */
int close_file(int file_descriptor);

/**
 * @brief Get the str from path object
 * 
 * @param path of the file
 * @return char * of the content of the file, NULL if an error occured
 */
char *get_str_from_path(char const *path);

/**
 * @brief Get the array from path of file
 * 
 * @param path of the file
 * @param delim_points where you want to cut the string
 * @param array where you need to put the array
 * @return int SUCCESS if the array was created, negative number if an error occured
 */
int get_array_from_path(char const *path, char const *delim_points, char ***array);

/**
 * @brief Get the array from str object
 * 
 * @param str string you want to parse
 * @param delim_points where you want to cut the string
 * @return char ** if the string is ok, NULL if an error occured
 */
char **get_array_from_str(char const *str, char const *delim_points);

/**
 * @brief Replace all old_char by new_char in str
 * 
 * @param str 
 * @param old_char 
 * @param new_char 
 * @return int SUCCESS if the array was replaced, negative number if an error occured
 */
int replace_char_in_str(char *str, char old_char, char new_char);

/**
 * @brief Replace all old_char by new_char in array
 * 
 * @param array 
 * @param old_char 
 * @param new_char 
 * @return int SUCCESS if the array was replaced, negative number if an error occured
 */
int replace_char_in_array(char **array, char old_char, char new_char);

/**
 * @brief To know if char c is in str delim
 * 
 * @param c char you want to check
 * @param delim array of delimiter char
 * @return true if c is in delim, false otherwise
 */
bool is_char_delim(char c, char const *delim);

/**
 * @brief To know the number of delimiter in str
 * 
 * @param str 
 * @param delim string with delimiter
 * @return int 
 */
int count_nb_delim(char const *str, char const *delim);

/**
 * @brief Get the size of word
 * 
 * @param str where is placed the word
 * @param delim array of delimiter char
 * @return size_t the size of the word, negative number if an error occured
 */
size_t get_size_word(char const *str, char const *delim);

/**
 * @brief Put the word before the delimiter in emplacement
 * 
 * @param word string where is placed the word
 * @param emplacement string where you need to put the word
 * @param delim array of delimiter char
 * @param i index if you need to update him
 */
void get_word(char const *word, char *emplacement, char const *delim, int *i);

#endif
