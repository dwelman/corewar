/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:16:17 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/18 12:57:04 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

int	check_command(char *com, t_info *info)
{
	int	i;

	i = 1;
	while (i < OP_COUNT + 1)
	{
		if (strcmp(com, info->op_tab[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
