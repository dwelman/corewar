/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 08:56:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/01 13:04:30 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	new_cor(char *cor_file, int player_num, t_cor *cor)
{
	if (cor == NULL)
		return ;
	cor->file = cor_file;
	cor->p_num = player_num;
}
