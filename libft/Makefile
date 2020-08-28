# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaila <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 07:32:20 by nmaila            #+#    #+#              #
#    Updated: 2019/09/03 17:39:38 by nmaila           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@echo "compiling..."
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@echo "creating $(NAME)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -fr $(OBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all

