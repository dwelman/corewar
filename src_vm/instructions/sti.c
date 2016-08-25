/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:44:58 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/25 13:03:11 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	sti_reg(t_op_run *run, t_env *env, int player)
{

}

void	sti_dir(t_op_run *run, t_env *env, int player)
{

}

/*
** Stores REG_SIZE bytes from the first argument into the second
*/

void	sti(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;

	player = run->player - 1;
	if (run->arg_types[1] == IND_CODE)
	{
		temp_val = read_int(run->arg[1]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
		temp_val = read_int(mem);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
		ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[0]) - 1], (void *)mem,
				REG_SIZE);
		free(mem);
		//print_memory(P_CPU(player).registers[*(int *)(run->arg[0]) - 1], REG_SIZE);
	}
	else if (run->arg_types[1] == REG_CODE)
	{
		ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[0]) - 1], 
				P_CPU(player).registers[*(int *)(run->arg[1]) - 1], REG_SIZE);
		//print_memory(P_CPU(player).registers[*(int *)(run->arg[0]) - 1], REG_SIZE);
	}
	else
	{

	}
	exit(0);
}
