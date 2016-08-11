/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:11:53 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/11 15:22:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

int	read_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
		{
			if (check_label(line, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}
