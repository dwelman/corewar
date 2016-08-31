/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:30:31 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 12:15:32 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int			handle_args(t_op_run *run, t_env *env, int player, int param)
{
	int	ret;

	if (run->arg_types[param] == DIR_CODE)
		ret = (int)read_short(run->arg[param]);
	else
		ret = read_int(P_REG(player, (int)*run->arg[param]));
	//printf("ret = %d\n", ret);	
	return (ret);
}

static int	check_reg(t_op_run *run)
{
	if ((int)*run->arg[2] > REG_NUMBER || run->arg_types[2] != REG_CODE)
		return (1);
	else
		return (0);
}

static int	return_temp(t_op_run *run, t_env *env, int player)
{
	int		temp_val;
	char	*mem;

	temp_val = 0;
	if (run->arg_types[0] == DIR_CODE)
	{
		temp_val = read_int(run->arg[0]);
		temp_val += handle_args(run, env, player, 1);
	}
	else if (run->arg_types[0] == IND_CODE)
	{
		temp_val = (int)read_short(run->arg[1]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, IND_SIZE);
		temp_val = (int)read_short(mem);
		temp_val += handle_args(run, env, player, 1);
		free(mem);
	}
	else if (run->arg_types[0] == REG_CODE)
	{
		temp_val = read_int(P_REG(player, (int)*run->arg[0]));
		temp_val += handle_args(run, env, player, 1);
	}
	return (temp_val);
}

/*
** Loads REG_SIZE bytes from the address given by the first two parameters into
** the last parameter
*/

void		ldi(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;

	player = run->p_in;
	temp_val = 0;
	if (check_reg(run) == 0)
	{
		P_CPU(player).carry = 0;
		return ;
	}
	if (run->arg_types[0] == REG_CODE || run->arg_types[0] == IND_CODE ||
			run->arg_types[0] == DIR_CODE)
		temp_val = return_temp(run, env, player);
	else
	{
		P_CPU(player).carry = 0;
		return ;
	}
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
			(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	ft_memcpy(P_REG(player, (int)*run->arg[2]), mem, REG_SIZE);
	P_CPU(player).carry = 1;
}