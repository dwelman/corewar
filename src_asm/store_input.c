/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 10:45:42 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/01 12:43:31 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		count_lines(char *name)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		count++;
	}
	close(fd);
	if (count == 0)
	{
		ft_putstr("Error : Input file cannot be empty\n");
		exit(0);
	}
	return (count);
}

void	store_input(t_info *info, char *name)
{
	int		count;
	int		fd;
	char	*line;

	info->input = (char **)malloc(sizeof(char *) * (count_lines(name) + 1));
	fd = open(name, O_RDONLY);
	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		info->input[count] = ft_strdup(line);
		free(line);
		count++;
	}
	info->input[count] = NULL;
	close(fd);
}