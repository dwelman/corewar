/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/22 13:51:56 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	display_players(t_env *env)
{
	int i;

	i = 0;
	while (i < env->p_count)
	{
		printf("player %s , number %d\n", env->players[i].file,
				env->players[i].p_num);
		i++;
	}
}

void	winner_output(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).p_num == env->last_live)
		{
			ft_printf("Player %d, %s has won!\n", PLAYER(p).p_num,
					PLAYER(p).name);
			return ;
		}
		p++;
	}
	ft_printf("Nobody won, no live instructions were executed properly... \
			dissapointing.\n");
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
	if (env.dump == FALSE)
		winner_output(&env);
	ft_printf("HELLO\n");
	//cleanup_env(&env);
	return (0);
}
