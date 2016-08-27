/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:44:58 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 22:11:52 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*void	sti_reg(t_op_run *run, t_env *env, int player)
{

}

void	sti_dir(t_op_run *run, t_env *env, int player)
{

}*/

int		get_number(t_op_run *run, t_env *env, int player)
{
	int	temp;
	
	temp = 0;
	if (run->arg_types[2] == REG_CODE)
	{	
		temp = read_int(P_CPU(player).registers[*(int *)(run->arg[2]) - 1]);
	}
	else
	{
		temp = get_num(run->arg[2], IND_SIZE);
	}
	return (temp);
}

/*
** Stores REG_SIZE bytes from the first argument into the second
*/

void	sti(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;

	player = run->p_in;
	temp_val = 0;
	if (run->arg_types[1] == IND_CODE)
	{
		temp_val = *(int *)(run->arg[1]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, IND_SIZE);
		//print_memory(mem, IND_SIZE);
		temp_val = get_num(mem, 2);
		printf("val = %d\n", temp_val);
		temp_val += get_number(run, env, player);
		free(mem);
	}
	else if (run->arg_types[1] == REG_CODE)
	{
		temp_val = read_int(P_CPU(player).registers[*(int *)(run->arg[2]) - 1]);
		temp_val += get_number(run, env, player);
	}
	else if (run->arg_types[1] == DIR_CODE)
	{
		temp_val = get_num(run->arg[1], IND_SIZE);
		printf("val = %d\n", temp_val);
		temp_val += get_number(run, env, player);
		printf("val = %d\n", temp_val);
	}
	//print_memory(P_CPU(player).registers[*(int *)(run->arg[0]) - 1], REG_SIZE);
	cwrite_bytes(env, (P_CPU(player).pc - env->memory) + (temp_val
				% IDX_MOD), (char *)P_CPU(player).registers
			[*(int *)(run->arg[0]) - 1], IND_SIZE);
	//print_memory(env->memory, MEM_SIZE);
	exit(0);
}
