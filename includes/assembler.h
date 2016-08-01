/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 08:13:56 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/01 12:13:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Corewar project by team Codamancers:
** daviwel, ddu-toit, ggroener, vivan-de
*/

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "../libft/libft.h"

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPERATOR_CHAR ','
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)

typedef struct	s_info
{
	int		fd;
	char	**input;
}				t_info;

typedef struct	s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}				t_header;

int				error_check(int argc, char **argv);

void			store_input(t_info *info, char *name);

#endif
