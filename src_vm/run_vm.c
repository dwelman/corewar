/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 10:53:20 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/01 15:53:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int		done(t_env *env)
{
	static int	last_live_check = 0;
	static int	checks;
	static int	last_change = 0;

	if (last_live_check == env->cycle_to_die)
	{
		puts("Totaly checking if live and stuff");
		last_change++;
		last_live_check = 0;
		checks++;
		if (last_change == MAX_CHECKS)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			last_change = 0;
			ft_printf("decreased! %d\n", env->cycle_to_die);
		}
	}
	last_live_check++;
	return (0);
}

void	run_vm(t_env *env)
{
	int	cycle;
	
	cycle = 1;
	while (!(done(env)))
	{
//		ft_printf("cycle = %d\n", cycle);
		cycle++;
	}
}
