/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 10:53:20 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/04 16:50:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		done(t_env *env)
{
	static int	last_live_check = 0;
	static int	checks;
	static int	last_change = 0;

	if (env->cycle_to_die <= 0)
		return (1);
	last_live_check++;
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
	return (0);
}

void	run_vm(t_env *env)
{
	long int	cycle;
	int			p_active;

	p_active = env->p_count;
	cycle = 1;
	while (!(done(env)))
	{
		ft_printf("cycle_to_die = %d\n", env->cycle_to_die);
		if (cycle == (long int)env->dump_cycles)
		{
			ft_printf("DUMP at cycle %ld\n", cycle);
			print_memory(env->memory, MEM_SIZE); 
			exit(1);
		}

		cycle++;
	}
}
