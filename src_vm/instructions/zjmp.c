/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 10:24:03 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/25 12:23:20 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		make_int(char *arg, int bytes)
{
	char		buf[4];
	size_t		i;
	int			ret;

	ft_memcpy(buf, arg, bytes);
	i = bytes;
	while (i < sizeof(int))
	{
		buf[i] = 0xff;
		i++;
	}
	ret = *(int*)buf;
	return (ret);
}

void	zjmp(t_op_run *run, t_env *env)
{
	int		index;
	int		p_in;

	reverse_bytes(run->arg[0], run->arg_sizes[0]);
	print_memory(run->arg[0], 2);
	index = make_int(run->arg[0], run->arg_sizes[0]);
	p_in = is_player(run->player, env);
	if (p_in != -1)
	{
		move_pc(&P_CPU(p_in), -1 , env);
		if (P_CPU(p_in).carry == 1)
		{
			move_pc(&P_CPU(p_in), index % IDX_MOD, env);
		}
	}
}
