# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/08/16 09:34:36 by vivan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

PATH = src/

IN_PATH = instructions/

IN_FILES = live.c\
		   zjmp.c

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
	  run_instr.c\
	  live_check.c
	 
OBJ = $(SRC:.c=.o)

IN_SRC = $(addprefix $(IN_PATH), $(IN_FILES))

IN_OBJ = $(IN_FILES:.c=.o)

INCLUDES = -I ../includes/ -I ../libft

ATTACH = -L  ../libft -lft

all: $(NAME)

$(NAME):
	clang -Wall -Werror -Wextra -c -g3 $(SRC) $(IN_SRC) $(INCLUDES) 
	clang -Wall -Werror -Wextra -o  $(NAME) $(OBJ) $(IN_OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ) $(IN_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
