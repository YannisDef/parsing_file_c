##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## classic Makefile with with unit tests
##

CC	=	gcc


##?				NORMAL TESTS
MAIN	=	src/main.c	\

SRC		=	src/close_file.c				\
			src/open_file.c					\
			src/get_array_from_path.c		\
			src/get_array_from_str.c		\
			src/get_file_size.c				\
			src/get_str_from_path.c			\
			src/read_file.c					\
			src/replace_char_in_array.c		\
			src/replace_char_in_str.c		\
			src/is_char_delim.c				\
			src/count_nb_delim.c			\
			src/get_size_word.c				\
			src/get_word.c					\

OBJ		=	$(SRC:.c=.o)

NAME	=	parsing

CPPFLAGS	=	-I./include

CFLAGS	=	-Werror -Wextra

COVER		=	--coverage

CRITERION	=	-lcriterion

TEST_NAME	=	unit_tests

SRC_TEST	=	tests/unit_tests/basic_tests.c	\
				$(SRC)							\

OBJ_TEST	=	$(SRC_TEST:.c=.o)

GCDA		=	*.gcda
GCNO		=	*.gcno

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CPPFLAGS) $(CLIBS)

tests_run:	$(OBJ_TEST)
	$(MAKE) fclean
	$(CC) -o $(TEST_NAME) $(COVER) $(CPPFLAGS) $(SRC_TEST) $(CRITERION)
	./$(TEST_NAME)

debug:	CPPFLAGS += -g3
debug:	make re

tests_clean:
	$(RM) $(OBJ_TEST)
	$(RM) $(GCDA)
	$(RM) $(GCNO)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re:	fclean all

.PHONY: all debug tests_clean clean fclean re