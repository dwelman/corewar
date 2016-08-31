/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 10:24:03 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/30 09:07:52 by ddu-toit         ###   ########.fr       */
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

	print_memory(run->arg[0], 2);
	index = (int)read_short(run->arg[0]);
	print_memory(&index, 4);
	ft_printf("index = %d\n", index);
	ft_printf("p_in = %d\n", run->p_in);
	if (run->p_in != -1)
	{
		if (P_CPU(run->p_in).carry == 1)
		{
			ft_printf("\nBefore PC : %ld\n", P_CPU(run->p_in).pc);
			move_pc(&P_CPU(run->p_in), index % IDX_MOD, env);
			ft_printf("\nAfter PC : %ld\n", P_CPU(run->p_in).pc);
		}
	}
}
