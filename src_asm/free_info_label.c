/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_lable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:07:20 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/22 12:16:02 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		free_info_label(t_info *info)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_label	*temp;
	int		last;

	tmp1 = info->labels;
	last = 0;
	while (tmp1->next != NULL || (tmp1->next == NULL && last++ == 0))
	{
		if (tmp1->next != NULL)
			tmp2 = tmp1->next;
		temp = (t_label *)tmp1->data;
		free(temp->name);
		free(tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
	}
}
