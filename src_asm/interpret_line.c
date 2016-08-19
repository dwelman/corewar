/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:09:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:31:31 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Finds whether a line has a label or not
*/

int	check_for_label(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != COMMENT_CHAR)
	{
		if (str[i] == LABEL_CHAR)
		{
			if (str[i - 1] != DIRECT_CHAR)
				return (i + 1);
		}
		i++;
	}
	return (0);
}

/*
** Reads the current line to see if it has a command on it, and if it does it
** stores that command
*/

int	interpret_line(char *str, t_info *info, int i)
{
	int	j;
	int	start_reading;
	int	found_command;

	start_reading = check_for_label(str);
	found_command = 0;
	j = start_reading;
	while (str[j] != '\0' && str[j] != COMMENT_CHAR)
	{
		if (found_command == 0 && str[j] != ' ' && str[j] != '\t')
		{
			info->line_nbr = i + 1;
			if (get_command(info, str, &j, &found_command) == -1)
				return (-1);
		}
		j++;
	}
	info->com = NULL;
	return (0);
}
