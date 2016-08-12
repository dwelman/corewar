# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/08/12 09:40:42 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

PATH = src/

IN_PATH = instructions/

SRC_P =  $(IN_PATH)live.c\


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
	  arg_info.c\
	  no_n_byte.c\
	  move_pc.c\
	  load_into_vm.c\
	  load_bytes.c\
	  sort_players.c\
	  print_memory.c\
	  print_ops.c\
	  cleanup.c\
	 
OBJ = $(SRC:.c=.o)

IN_OBJ = $(SRC_P:.c=.o)

INCLUDES = -I ../includes/ -I ../libft

ATTACH = -L  ../libft -lft

all: $(NAME)

$(NAME):
	/bin/mv $(IN_OBJ) $(IN_PATH)
	clang -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	clang -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
