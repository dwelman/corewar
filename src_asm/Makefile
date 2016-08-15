# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/29 09:15:12 by daviwel           #+#    #+#              #
#    Updated: 2016/08/15 12:56:08 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = main.c \
	  error_check.c \
	  store_input.c \
	  validate_input.c \
	  validate_n_c.c \
	  start_compile.c \
	  init_header.c \
	  reverse_bytes.c \
	  write_file.c \
	  print_mem.c \
	  read_line.c \
	  check_label.c \
	  fill_optab.c \
	  fill_subfunc.c \
	  interpret_line.c \
	  get_command.c \
	  check_n_c.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

INCLUDES = -I ../includes/ -I ../libft/

ATTACH = -L ../libft/ -lft

all: $(NAME)

$(NAME):
	clang $(CFLAG) $(INCLUDES) -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC) ../includes
