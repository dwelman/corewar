/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 10:53:20 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/13 08:02:18 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		done(t_env *env)
{
	static int	checkups = 0;
	if (env->cycle_to_die <= 0)
		return (1);
	check_live_calls(env);
	if (env->live_calls == NBR_LIVE)
	{
		if (still_alive(env))
			env->cycle_to_die -= CYCLE_DELTA;
		else if (checkups == MAX_CHECKS)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			checkups = -1;
		}
		env->live_calls = 0;
		checkups++;
	}
	if (count_alive(env) == 0)
		return (1);
/*	last_live_check++;
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
*/	return (0);
}

void	fetch_ops(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).alive == TRUE)
		{
			if (CUR_OP(p).reset == TRUE && *P_CPU(p).pc >= 1 && *P_CPU(p).pc <= 16)
				PLAYER(p).cur_op = load_op(&PLAYER(p), env);
		}
		p++;
	}
}

void	exec_ops(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).alive == TRUE)
		{
			if (CUR_OP(p).to_exec == 1 && CUR_OP(p).op >= 1 && CUR_OP(p).op <= 16)
			{
				ft_printf("\nplayer %d exec %s\n",PLAYER(p).p_num, OP(CUR_OP(p).op).name);
				get_args(&CUR_OP(p), env, P_CPU(p).pc);
				run_instr(&CUR_OP(p), env);
				move_pc(&P_CPU(p), total_arg_size(CUR_OP(p).arg_sizes), env);
				if (P_CPU(p).pc > P_CPU(p).prog_start + PLAYER(p).size)
					PLAYER(p).alive = FALSE;
				print_oprun(CUR_OP(p), env);
				clear_op(&CUR_OP(p), env);
			}
			else
				CUR_OP(p).to_exec--;
		}
		p++;
	}
}

void	run_vm(t_env *env)
{
	long int	cycle;
	int			p_active;

	p_active = env->p_count;
	cycle = 1;
	puts("=================START==================");
	env->alive_at_check = (int*)malloc(sizeof(int) * env->p_count);
	set_alive_at_check(env);
	ft_printf("AAC : \n");
	print_memory(env->alive_at_check, sizeof(int) * env->p_count);
	while (!(done(env)))
	{
		fetch_ops(env);
		exec_ops(env);
		if (cycle == (long int)env->dump_cycles)
		{
			ft_printf("DUMP at cycle %ld\n", cycle);
			print_memory(env->memory, MEM_SIZE);
			break ;	
		}
		inc_last_live(env);
		cycle++;
	}
	ft_memdel((void**)&env->alive_at_check);
}
