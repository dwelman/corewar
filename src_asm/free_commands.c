/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 09:16:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/22 15:39:59 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	free_commands(t_info *info)
{
	//PLEASE FIX, MALLOC ERRORS
	t_list		*tmp1;
	t_list		*tmp2;
	//int			i;
	//t_command	*temp;

	tmp1 = info->commands;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(tmp1);
}
