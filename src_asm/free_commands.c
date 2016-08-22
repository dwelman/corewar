/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 09:16:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/22 09:38:27 by daviwel          ###   ########.fr       */
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
		//i = 0;
		tmp2 = tmp1->next;
		//temp = (t_command *)tmp1->data;
		//while (temp->params[i])
		//{
		//	free(temp->params[i]);
		//	i++;
		//}
		//free(tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
	}
	free(tmp1);
}
