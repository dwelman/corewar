# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/08/28 12:34:45 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

PATH = src/

SRC = $(PATH)main.c\

OBJ = $(SRC:.c=.o)

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: qme $(NAME)

$(NAME):
	clang -Wall -Werror -Wextra -c $(SRC)
	/bin/mv *.o src
	clang -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

format: me

qme:
	@rm -Rf author
	@echo daviwel > author
	@echo ddu-toit >> author
	@echo vivan-de >> author
	@echo ggroener >> author

me: qme
	cat -e author
