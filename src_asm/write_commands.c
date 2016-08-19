/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:50:01 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:39:28 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	handle_params(t_info *info, t_command *com, int fd)
{
	int		i;
	int		k;
	char	temp_char;
	int		temp_int;
	int		offset;

	i = 0;
	while (i < com->num_params)
	{
		if (com->params[i][0] == 'r')
		{
			temp_char = (char)ft_atoi(&com->params[i][1]);
			write(fd, &temp_char, sizeof(char));
		}
		else if (com->params[i][0] == DIRECT_CHAR)
		{
			if (com->params[i][1] != LABEL_CHAR)
			{
				if (com->dir_as_index == TRUE)
				{
					temp_int = ft_atoi(++com->params[i]);
					reverse_bytes(&temp_int, IND_SIZE);
					write(fd, &temp_int, IND_SIZE);
				}
				else
				{
					temp_int = ft_atoi(++com->params[i]);
					reverse_bytes(&temp_int, DIR_SIZE);
					write(fd, &temp_int, DIR_SIZE);
				}
			}
			else
			{
				if ((k = find_label_line(info, ft_strchr(com->params[i],
									LABEL_CHAR))) != -1)
				{
					//ft_printf("label = %s, lien = %d\n", com->params[i], k);
					offset = count_bytes_between(info, com->line_nbr, k);
					reverse_bytes(&offset, 2);
					write(fd, &offset, 2);
				}
				else
				{
					exit(-1);
				}
			}
		}
		else
		{
			temp_int = ft_atoi(com->params[i]);
			write(fd, &temp_int, IND_SIZE);
		}
		i++;
	}
}

/*
** Writes all the commands to the .cor file
*/

void	write_commands(t_info *info, int fd)
{
	t_list		*crawl;
	t_command	*com;

	crawl = info->commands;
	while (crawl != NULL)
	{
		com = (t_command *)crawl->data;
		write(fd, &com->opcode, sizeof(com->opcode));
		if (com->encoding_byte != '\0')
			write(fd, &com->encoding_byte, sizeof(com->encoding_byte));
		handle_params(info, com, fd);
		crawl = crawl->next;
	}
}
