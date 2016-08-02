# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/08/02 10:02:13 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

PATH = src/

SRC = main.c\
	  check_input.c\
	  dupl_num.c\
	  check_int.c\
	  get_input.c\
	  set_structs.c\
	  run_vm.c\
	  print_memory.c

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
