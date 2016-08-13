/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 08:18:18 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/13 07:12:32 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Checks if player number exists and returns index of player.
*/

int	is_player(int player, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->p_count)
	{
		ft_printf("i = %d\n", i);
		if (PLAYER(i).p_num == player)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Executes live instruction - sets env->last_live to the argument of 
** the instruction if player exists and is alive.
*/

void	live(t_op_run *run, t_env *env)
{
	int	player;
	int	index;

	ft_printf("arg size %d \n", run->arg_sizes[0]);
	print_memory(run->arg[0], 4);
	reverse_bytes((void*)run->arg[0], 4);
	ft_printf("derpa\n");
	player = *(int*)run->arg[0];
	index = is_player(player, env);
	ft_printf("live with player %d\n", player);
	if (index != -1 && PLAYER(index).alive == TRUE)
	{
		env->last_live = player;
		PLAYER(index).last_live = -1;
		env->live_calls++;
	}
}
