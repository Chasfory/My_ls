##
## EPITECH PROJECT, 2021
## makefile
## File description:
## semestre1
##

MAIN			=	src/main.c\

SRC     		=   src/my_ls.c	\
					src/my_spe_ls.c\
					src/my_file_to_folder.c\

SRC_TEST		=		$(SRC)
SRC_TEST        +=       tests/test.c

OBJ     		=       $(SRC:.c=.o)	\
						$(MAIN:.c=.o)

OBJ_TEST    		=       $(SRC_TEST:.c=.o)

NAME    		=       my_ls

LIB_FLAGS		=	-L./lib/my -lmy

CFLAGS  		+=       -Wall -Wextra

CRIT_FLAGS      =       --coverage -lcriterion -lgcov

NAME_TEST       =       unit_test

CPPFLAGS		=	-I./include

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(LIB_FLAGS)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my
	rm -f -r *~
	rm -f *gc*

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)
	rm -f $(NAME_TEST)

unit_test: $(OBJ_TEST)
	make -C ./lib/my
	gcc -o $(NAME_TEST) $(OBJ_TEST) $(LIB_FLAGS) $(CRIT_FLAGS)

tests_run: unit_test
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/

re: fclean all

.PHONY: all clean fclean unit_test tests_run re