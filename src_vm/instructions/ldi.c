/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:11:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/24 15:10:33 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		get_param_val(t_op_run *run, t_env *env, int player)
{
	int	temp_val;

	if (run->arg_types[1] == REG_CODE)
	{
		return (read_int(P_CPU(player).registers[*(int *)(run->arg[1]) - 1]));
	}
	else
	{
		temp_val = read_int(run->arg[1]);
		return (read_int(cload_bytes(env->memory, (P_CPU(player).pc - env->memory)
						+ (temp_val % IDX_MOD), MEM_SIZE, REG_SIZE)));
	}
}

/*
** Reads REG_SIZE bytes at the address created by finding the value at the
** address of the first character and adding the second character to it, these
** bytes are stored in the third param
*/

void	ldi(t_op_run *run, t_env *env)
{
	int		player;
	int		temp_val;
	int		temp;
	char	*mem;

	player = run->player;
	temp = get_param_val(run, env, player);
	ft_printf("temp = %d\n", temp);
	if (run->arg_types[0] == REG_CODE)
	{
		temp_val = read_int(P_CPU(player).registers[*(int *)(run->arg[0]) - 1]);
		temp_val += temp;
		P_CPU(player).registers[*(int *)(run->arg[2]) - 1] = &temp_val;
	}
	else
	{
		print_memory(run->arg[0], IND_SIZE);
		temp_val = read_int(run->arg[0]);
		ft_printf("temp val = %d\n", temp_val);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, IND_SIZE);
		reverse_bytes((void *)mem, IND_SIZE);
		temp_val = read_int(mem);
		temp_val += temp;
		P_CPU(player).registers[*(int *)(run->arg[2]) - 1] = &temp_val;
	}
	print_memory(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], REG_SIZE);
	exit(0);
}
