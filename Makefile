NAME = minishell
FLAGS = -Wall -Werror -Wextra
LIB = ./libft/libft.a

SRC = ./sources/main.c ./sources/parameter_search.c ./sources/ft_strarrrealloc.c \
		./sources/ft_setenv.c ./sources/unsetenv.c ./sources/print_error.c ./sources/ft_cd.c \
		./sources/parser.c ./sources/expand.c ./sources/ft_echo.c ./sources/access_control.c

OBJ = main.o parameter_search.o ft_strarrrealloc.o \
		ft_setenv.o unsetenv.o print_error.o ft_cd.o \
		parser.o expand.o ft_echo.o access_control.o

all: $(NAME)

$(NAME):
	@make -C libft/ libft.a
	gcc $(FLAGS) -c $(SRC) -g
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

libft:
	make -C libft/ libft.a

clean:
	make -C libft/ clean
	rm -fr $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -fr $(NAME)

re: fclean all