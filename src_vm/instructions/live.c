/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 08:18:18 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 14:07:56 by ddu-toit         ###   ########.fr       */
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
	int	p;
	int	index;

	player = read_int(run->arg[0]);
	index = is_player(player, env);
	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).p_num == player)
		{
			env->last_live = player;
			PLAYER(p).last_live = -1;
			env->live_calls++;
		}
		p++;
	}
/*//	printf("index = %d player = %d\n", index, player);
	if (index != -1 && PLAYER(index).alive == TRUE)
	{
		ft_printf("A process shows that player %s is alive\n", PLAYER(index).name);//
		env->last_live = player;
		PLAYER(index).last_live = -1;
		env->live_calls++;
	}*/
}
