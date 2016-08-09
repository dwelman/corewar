/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:21:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/08 14:39:57 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	write_file(t_info *info)
{
	int		fd;
	int		i;
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
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write(fd, &info->header, sizeof(info->header));
	print_memory(&info->header, sizeof(t_header));
	close(fd);
}
