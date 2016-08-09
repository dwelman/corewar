# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/08/09 12:56:51 by ddu-toit         ###   ########.fr        #
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
	  fill_optab.c\
	  fill_subfunc.c\
	  load_program.c\
	  reverse_bytes.c\
	  read_byte_val.c\
	  run_vm.c\
	  load_op.c\
	  load_into_vm.c\
	  load_bytes.c\
	  sort_players.c\
	  print_memory.c\
	  print_ops.c\
	  cleanup.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I ../includes/ -I ../libft

ATTACH = -L ./ -lft

all: $(NAME)

$(NAME):
	clang -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	clang -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
