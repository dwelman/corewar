/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:21:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:52:17 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	add_null(int fd, int padding)
{
	while (padding % 4 != 0)
	{
		write(fd, "\0", 1);
		padding++;
	}
}

/*
** Writes the header to the .cor file and creates a new file
*/

void	add_cor(char *file_name, int *i)
{
	file_name[*i += 1] = '.';
	file_name[*i += 1] = 'c';
	file_name[*i += 1] = 'o';
	file_name[*i += 1] = 'r';
	file_name[*i += 1] = '\0';
}

void	write_file(t_info *info)
{
	int		fd;
	int		i;
	int		padding;
	char	file_name[PROG_NAME_LENGTH + 5];

	i = -1;
	while (info->file_name[++i] != '.')
		file_name[i] = info->file_name[i];
	add_cor(&(*file_name), &i);
	reverse_bytes((void *)&info->header.magic, sizeof(info->header.magic));
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0666);
	padding = sizeof(info->header.magic);
	write(fd, &info->header.magic, sizeof(info->header.magic));
	add_null(fd, padding);
	padding = sizeof(info->header.prog_name);
	write(fd, &info->header.prog_name, sizeof(info->header.prog_name));
	add_null(fd, padding);
	padding = sizeof(info->header.prog_size);
	reverse_bytes((void *)&info->header.prog_size, sizeof(int));
	write(fd, &info->header.prog_size, sizeof(info->header.prog_size));
	add_null(fd, padding);
	padding = sizeof(info->header.comment);
	write(fd, &info->header.comment, sizeof(info->header.comment));
	add_null(fd, padding);
	write_commands(info, fd);
	close(fd);
}
