/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:50:01 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/18 15:46:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	handle_params(t_info *info, t_command *com, int fd)
{
	int	i;
	int	k;//
	char	temp_char;
	short	temp_short;
	int		temp_int;

	i = 0;
	k = info->num_labels;//
	temp_short = 0;
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
					ft_memcpy(&temp_short, &com->params[i], IND_SIZE);
					write(fd, &temp_short, IND_SIZE);
				}
				else
				{
					ft_memcpy(&temp_int, &com->params[i], DIR_SIZE);
					write(fd, &temp_int, DIR_SIZE);
				}
			}
		}
		else
		{
			ft_memcpy(&temp_short, &com->params[i], IND_SIZE);
			write(fd, &temp_short, IND_SIZE);
		}
		i++;
	}
}

void	write_commands(t_info *info, int fd)
{
	t_list		*crawl;
	t_command	*com;
	//int			int_temp;
	//short		short_temp;
	//char		char_temp;

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
