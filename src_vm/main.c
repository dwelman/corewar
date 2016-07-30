/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/30 11:24:13 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	init_env(t_env *env)
{
	env->p_count = 0;
	env->dump_cycles = 0;
	env->dump = FALSE;
	env->players = NULL;
}

void	display_players(t_env *env)
{
	int i = 0;

	while (i < env->p_count)
	{
		ft_printf("player %s , number %d\n", env->players[i].file, env->players[i].p_num);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env	env;

	check_args(argc, argv, &env);
	get_input(argc, argv, &env);
	display_players(&env);
	return (0);
}
