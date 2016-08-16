/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 07:35:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/16 11:19:15 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

t_list	*create_command(char *params, int *index, t_info *info)
{
	t_list		*link;
	t_command	*nc;

	nc = (t_command *)malloc(sizeof(t_command));
	nc->opcode = info->op_tab[*index].code;
	nc->op_tab_index = *index;
	nc->params = ft_strsplit(params, SEPERATOR_CHAR);
	nc->num_params = count_arr(nc->params);
	if (info->op_tab[nc->op_tab_index].n_byte == TRUE)
	{
		if ((nc->encoding_byte = get_encoding_byte(nc->params, nc->num_params,
			nc->op_tab_index, info)) == '\0')
			*index = -1;
	}
	link = ft_lstnew((void *)nc);
	return (link);
}
