/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:30:31 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 22:10:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		get_num(char *arg, int size)
{
	int	ret;
	
	reverse_bytes(arg, size);
	ret	= *(int *)arg;
	if (ret > SHORT_MAX || ret < SHORT_MIN)
		ret = make_int(arg, IND_SIZE);
	return (ret);
}

void	ldi_reg(t_op_run *run, t_env *env, int player)
{
	char	*mem;
	int		temp_val;

	print_memory(P_CPU(player).registers[*(int *)(run->arg[0]) - 1], REG_SIZE);
	temp_val = *(int *)(P_CPU(player).registers[*(int *)(run->arg[0]) - 1]);
	print_memory(&temp_val, REG_SIZE);
	if (run->arg_types[1] == DIR_CODE)
		temp_val += read_int(run->arg[1]);
	else
		temp_val += read_int(P_CPU(player).registers[*(int *)
				(run->arg[1]) - 1]);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], (void *)mem,
			REG_SIZE);
	//print_memory(mem, REG_SIZE);
	free(mem);
	print_memory(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], REG_SIZE);
	P_CPU(player).carry = 1;
}

void	ldi_ind(t_op_run *run, t_env *env, int player)
{
	char	*mem;
	int		temp_val;

	temp_val = read_int(run->arg[0]);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, IND_SIZE);
	reverse_bytes(mem, IND_SIZE);
	temp_val = read_int(mem);
	//print_memory(&temp_val, REG_SIZE);
	if (run->arg_types[1] == DIR_CODE)
		temp_val += read_int(run->arg[1]);
	else
	{
		temp_val += read_int(P_CPU(player).registers[*(int *)
				(run->arg[1]) - 1]);
	}
	//print_memory(&temp_val, REG_SIZE);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], (void *)mem,
			REG_SIZE);
	//print_memory(mem, REG_SIZE);
	free(mem);
	//print_memory(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], REG_SIZE);
	P_CPU(player).carry = 1;
}

/*
** Loads REG_SIZE bytes from the first parameter into the second parameter
*/

void	ldi(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;
	//int		temp;

	player = run->p_in;
	if (run->arg_types[0] == DIR_CODE)
	{
		temp_val = get_num(run->arg[0], run->arg_sizes[0]);
		if (run->arg_types[1] == DIR_CODE)
			temp_val += get_num(run->arg[1], run->arg_sizes[1]);
		else
		{
			temp_val += read_int(P_CPU(player).registers[*(int *)
					(run->arg[1]) - 1]);
		}
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
		ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], (void *)mem,
				REG_SIZE);
		//print_memory(mem, REG_SIZE);
		free(mem);
		P_CPU(player).carry = 1;
		//print_memory(P_CPU(player).registers[*(int *)(run->arg[2]) - 1], REG_SIZE);
	}
	else if (run->arg_types[0] == IND_CODE)
		ldi_ind(run, env, player);
	else if (run->arg_types[0] == REG_CODE)
		ldi_reg(run, env, player);
}
