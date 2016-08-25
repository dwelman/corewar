/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 09:16:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/25 11:52:27 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	free_commands(t_command *com)
{
	t_command	*temp;
	int			i;

		i = -1;
		temp = com;
		while (temp->params[++i])
			free(temp->params[i]);
		free(temp->params);
		free(temp);
}
