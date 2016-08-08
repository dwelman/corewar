/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/08 08:12:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	display_players(t_env *env)
{
	int i = 0;

	while (i < env->p_count)
	{
		printf("player %s , number %d\n", env->players[i].file, env->players[i].p_num);
		i++;
	}
}

void	cleanup_env(t_env *env)
{
	int	r;
	int	p;

	r = 0;
	p = 0;
	ft_memdel(&env->memory);
	while (p < env->p_count)
	{
		r = 0;
		while (r < REG_NUMBER)
		{
			ft_memdel(&P_REG(p, r));
			r++;
		}
		ft_memdel((void**)&P_CPU(p).registers);
		ft_memdel((void**)&PLAYER(p).name);
		ft_memdel((void**)&PLAYER(p).comment);
		ft_memdel((void**)&PLAYER(p).instructions);
		p++;
	}
	ft_memdel((void*)&env->players);
}

int		main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	check_args(argc, argv, &env);
	get_input(argc, argv, &env);
	display_players(&env);
	load_programs(&env);
	run_vm(&env);
	cleanup_env(&env);
	return (0);
}
