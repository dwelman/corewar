/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 08:13:56 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/08 12:42:26 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Corewar project by team Codamancers:
** daviwel, ddu-toit, ggroener, vivan-de
*/

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include <libft.h>
# include <corewar_vm.h>

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPERATOR_CHAR ','
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

# define INPUT info->input
# define LINE info->line_nbr

typedef struct	s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}				t_header;

typedef struct	s_info
{
	char		**input;
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	int			line_nbr;
	t_header	header;
}				t_info;

void    		print_memory(const void *addr, size_t size);

void			write_file(t_info *info);

void			init_header(t_header *header, t_info *info);

void			start_compile(t_info *info);

int				error_check(int argc, char **argv);

void			store_input(t_info *info, char *name);

void			validate_input(t_info *info);

void			check_nc(t_info *info);

#endif
