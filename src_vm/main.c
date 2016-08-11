/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/09 14:03:40 by ddu-toit         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	check_args(argc, argv, &env);
	get_input(argc, argv, &env);
	sort_players(&env);
	load_programs(&env);
	load_into_vm(&env);
	run_vm(&env);
	cleanup_env(&env);
	return (0);
}
