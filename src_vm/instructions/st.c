/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:48:47 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/27 11:19:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	print_registers(t_cpu *cpu)
{
	int	r;

	r = 0;
	while (r < REG_NUMBER)
	{
		ft_printf("r%d : ", r + 1);
		print_memory(cpu->registers[r], REG_SIZE);
		ft_putchar('\n');
		r++;
	}
}

static int	check_reg(t_op_run *run)
{
	if (run->arg_types[0] == REG_CODE)
	{
		if ((int)*run->arg[0] > REG_NUMBER)
			return (0);
	}
	if (run->arg_types[1] == REG_CODE)
	{
		if ((int)*run->arg[1] > REG_NUMBER)
			return (0);
	}
	else if (run->arg_types[1] != IND_CODE)
		return (0);
	return (1);
}

/*
** Stores REG_SIZE bytes from the first argument into the second
*/

void	st(t_op_run *run, t_env *env)
{
	int		player;
	int		temp_val;

	player = run->p_in;
	if (check_reg(run) == 0)
	{
		P_CPU(player).carry = 0;
		return ;
	}
	temp_val = 0;
	if (run->arg_types[1] == IND_CODE)
	{
		ft_memcpy(&temp_val, run->arg[1], IND_SIZE);
		reverse_bytes(&temp_val, IND_SIZE);
		print_memory(P_REG(player, (int)*run->arg[0]), 4);
		ft_memcpy(&P_CPU(player).pc[temp_val % IDX_MOD], 
				P_REG(player, (int)*run->arg[0]), REG_SIZE);
		//ADD CIRCULAR WRITE
		////
	}
	else
	{
		ft_memcpy(P_CPU(player).registers[(int)*(run->arg[0]) - 1], 
				P_CPU(player).registers[(int)*(run->arg[1]) - 1], REG_SIZE);
		print_memory(P_CPU(player).registers[(int)*(run->arg[0]) - 1], REG_SIZE);
	}
	P_CPU(player).carry = 1;
}
