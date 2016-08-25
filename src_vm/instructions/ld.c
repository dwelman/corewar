/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:51:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/25 09:34:41 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	ld_ind(t_op_run *run, t_env *env, int player)
{
	char	*mem;
	int		temp_val;

	temp_val = read_int(run->arg[0]);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	reverse_bytes(mem, REG_SIZE);
	temp_val = read_int(mem);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[1]) - 1], (void *)mem,
			REG_SIZE);
	//print_memory(mem, REG_SIZE);
	free(mem);
	//print_memory(P_CPU(player).registers[*(int *)(run->arg[1]) - 1], REG_SIZE);
	P_CPU(player).carry = 1;
}

/*
** Loads REG_SIZE bytes from the first parameter into the second parameter
*/

void	ld(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;

	player = run->player - 1;
	if (run->arg_types[0] == DIR_CODE)
	{
		//ft_printf("MEM = %s\n", P_CPU(player).pc + ft_atoi(run->arg[0]));
		temp_val = read_int(run->arg[0]);
		//print_memory(run->arg[0], sizeof(run->arg[0]));
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
		ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[1]) - 1], (void *)mem,
				REG_SIZE);
		//print_memory(mem, REG_SIZE);
		free(mem);
		P_CPU(player).carry = 1;
		//print_memory(P_CPU(player).registers[*(int *)(run->arg[1]) - 1], REG_SIZE);
	}
	else if (run->arg_types[0] == IND_CODE)
		ld_ind(run, env, player);
}
