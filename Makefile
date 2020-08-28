# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaila   <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 15:42:13 by nmaila            #+#    #+#              #
#    Updated: 2020/01/15 18:42:16 by nmaila           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./sources/main.c ./sources/parameter_search.c \
		./sources/ft_setenv.c ./sources/ft_unsetenv.c ./sources/mini_errorfunctions.c \
		./sources/ft_cd.c ./sources/parser.c ./sources/expand.c ./sources/ft_echo.c \
		./sources/print_env.c ./sources/access_control.c

OBJ = main.o parameter_search.o \
		ft_setenv.o ft_unsetenv.o mini_errorfunctions.o ft_cd.o \
		parser.o expand.o ft_echo.o print_env.o access_control.o

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

all: $(NAME)

$(NAME):
	#@make -C libft/ libft.a
	gcc $(FLAGS) -c $(SRC) -g
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

#libft:
	#make -C libft/ libft.a

clean:
	#make -C libft/ clean
	rm -fr $(OBJ)

fclean: clean
	#make -C libft/ fclean
	rm -fr $(NAME)

re: fclean all
