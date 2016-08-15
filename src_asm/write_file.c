/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:21:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/11 11:16:56 by daviwel          ###   ########.fr       */
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

void	write_file(t_info *info)
{
	int		fd;
	int		i;
	int		padding;
	char	file_name[PROG_NAME_LENGTH + 5];

	i = 0;
	while (info->header.prog_name[i] != '\0')
	{
		file_name[i] = info->header.prog_name[i];
		i++;
	}
	file_name[i++] = '.';
	file_name[i++] = 'c';
	file_name[i++] = 'o';
	file_name[i++] = 'r';
	file_name[i++] = '\0';
	reverse_bytes((void *)&info->header.magic, sizeof(info->header.magic));
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0666);
	padding = sizeof(info->header.magic);
	write(fd, &info->header.magic, sizeof(info->header.magic));
	add_null(fd, padding);
	padding = sizeof(info->header.prog_name);
	write(fd, &info->header.prog_name, sizeof(info->header.prog_name));
	add_null(fd, padding);
	padding = sizeof(info->header.prog_size);
	write(fd, &info->header.prog_size, sizeof(info->header.prog_size));
	add_null(fd, padding);
	padding = sizeof(info->header.comment);
	write(fd, &info->header.comment, sizeof(info->header.comment));
	add_null(fd, padding);
	//print_memory(&info->header.prog_name, sizeof(info->header.prog_name));
	close(fd);
}