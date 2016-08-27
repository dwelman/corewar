/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 12:15:21 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 12:20:04 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <corewar_vm.h>

/*
void	lld_ind(t_op_run *run, t_env *env, int player)
{
	char	*mem;
	int		temp_val;

	temp_val = read_int(run->arg[0]);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				temp_val, MEM_SIZE, REG_SIZE);
	reverse_bytes(mem, REG_SIZE);
	temp_val = read_int(mem);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				temp_val, MEM_SIZE, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[*(int *)(run->arg[1]) - 1], (void *)mem,
			REG_SIZE);
	//print_memory(mem, REG_SIZE);
	free(mem);
	//print_memory(P_CPU(player).registers[*(int *)(run->arg[1]) - 1], REG_SIZE);
	P_CPU(player).carry = 1;
}

void	lld(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;

	player = run->p_in;
	if (run->arg_types[0] == DIR_CODE)
	{
		//ft_printf("MEM = %s\n", P_CPU(player).pc + ft_atoi(run->arg[0]));
		temp_val = read_int(run->arg[0]);
		//print_memory(run->arg[0], sizeof(run->arg[0]));
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				temp_val, MEM_SIZE, REG_SIZE);
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
*/

void	lld_ind(t_op_run *run, t_env *env, int player)
{
	char	*mem;
	int		temp_val;

	temp_val = (int)read_short(run->arg[0]);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory)
			+ temp_val, MEM_SIZE, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[(int)*run->arg[1] - 1],
			(void *)mem, REG_SIZE);
	P_CPU(player).carry = 1;
	free(mem);
}

static int		check_reg(t_op_run *run)
{
	if ((int)*run->arg[1] > REG_NUMBER || run->arg_types[1] != REG_CODE)
		return (0);
	else
		return (1);
}

/*
** Loads REG_SIZE bytes from the first parameter into the second parameter
*/

void	lld(t_op_run *run, t_env *env)
{
	int		player;

	player = run->p_in;
	if (check_reg(run) == 0)
	{
		P_CPU(player).carry = 0;
		return ;
	}
	check_reg(run);
	if (run->arg_types[0] == DIR_CODE)
	{
		ft_memcpy(P_REG(player, (int)*run->arg[1]), run->arg[0], REG_SIZE);
		P_CPU(player).carry = 1;
	}
	else if (run->arg_types[0] == IND_CODE)
		lld_ind(run, env, player);
	else
		P_CPU(player).carry = 0;
}
