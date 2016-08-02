/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 08:56:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/02 11:45:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	init_cor(char *cor_file, int player_num, t_cor *cor)
{
	if (cor == NULL)
		return ;
	cor->file = cor_file;
	cor->p_num = player_num;
	cor->lsc = 0;
}

void	init_env(t_env *env)
{
	if (env == NULL)
		return ;
	env->p_count = 0;
	env->dump_cycles = 0;
	env->dump = FALSE;
	env->players = NULL;
	env->memory = malloc(MEM_SIZE);
	env->cycle_to_die = CYCLE_TO_DIE;
	env->checkups = 0;
	if (env->memory == NULL)
		arg_err(ER_MALLOC, "init_env");
}

void	init_cpu(t_cpu *cpu)
{
	int		r;

	if (cpu == NULL)
		return ;
	r = 0;
	cpu->pc = NULL;
	cpu->carry = 0;
	cpu->registers = (void**)malloc(sizeof(void*) * REG_NUMBER);
	if (cpu->registers == NULL)
		arg_err(ER_MALLOC, "init_cpu");
	while (r < REG_NUMBER)
	{
		cpu->registers[r] = malloc(REG_SIZE);
		if (cpu->registers[r] == NULL)
			arg_err(ER_MALLOC, "init_cpu");
		r++;
	}
}
