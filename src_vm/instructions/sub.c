/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:28:25 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/23 10:46:07 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Subtracts the values of the first 2 registers and stores it in the 3rd
*/

void	sub(t_op_run *run, t_env *env)
{
	int	player;
	int	temp;

	player = run->player - 1;
	temp = 0;
	temp += read_int(P_CPU(player).registers[*(int *)(run->arg[0]) - 1]);
	temp -= read_int(P_CPU(player).registers[*(int *)(run->arg[1]) - 1]);
	reverse_bytes(&temp, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], &temp, REG_SIZE);
	P_CPU(player).carry = 1;
}
