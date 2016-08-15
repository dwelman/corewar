/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:09:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/15 12:51:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

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

int	interpret_line(char *str, t_info *info)
{
	int	i;
	int	start_reading;
	int	found_command;

	start_reading = check_for_label(str);
	found_command = 0;
	i = start_reading;
	while (str[i] != '\0' && str[i] != COMMENT_CHAR)
	{
		if (found_command == 0 && str[i] != ' ' && str[i] != '\t')
		{
			get_command(info, str, &i, &found_command);
		}
		i++;
	}
	info->com = NULL;
	return (0);
}
