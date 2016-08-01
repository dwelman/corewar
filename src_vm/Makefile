# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/07/30 09:00:27 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

PATH = src/

SRC = main.c\
	  check_input.c\
	  dupl_num.c\
	  check_int.c\
	  get_input.c\
	  new_cor.c

OBJ = $(SRC:.c=.o)

ATTACH = -L ./ -lft

all: $(NAME)

$(NAME):
	clang -Wall -Werror -Wextra -c $(SRC)
	clang -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
