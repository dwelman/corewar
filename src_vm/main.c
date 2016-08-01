/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/01 15:48:23 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	display_players(t_env *env)
{
	int i = 0;

	while (i < env->p_count)
	{
		printf("player %s , number %d\n", env->players[i].file, env->players[i].p_num);//
		i++;
	}
}

void	cleanup_env(t_env *env)
{
	int	r;

	r = 0;
	ft_memdel(&env->memory);
	ft_memdel((void*)&env->players);
	while (r < REG_NUMBER)
	{
		ft_memdel(&CPU.registers[r]);
		r++;
	}
	if (CPU.registers)
		free(CPU.registers);
	CPU.registers = NULL;
}


int		main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	check_args(argc, argv, &env);
	get_input(argc, argv, &env);
	display_players(&env);
	init_cpu(&env.cpu);
	run_vm(&env);
	cleanup_env(&env);
	return (0);
}
