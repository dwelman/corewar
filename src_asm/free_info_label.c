/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_lable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:07:20 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/21 16:45:13 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		free_info_label(t_info *info)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = info->labels;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
	}
	free(tmp1);
}
