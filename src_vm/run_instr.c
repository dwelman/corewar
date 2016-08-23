/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 09:21:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/23 12:10:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Runs the correct function depending on given t_op_run struct.(opcode)
*/

void	run_instr(t_op_run *run, t_env *env)
{
	int	code;

	code = run->op;
	if (code == LIVE)
		live(run, env);
	else if (code == LD)
		ld(run, env);
	else if (code == ST)
		st(run, env);
	else if (code == ADD)
		add(run, env);
	else if (code == SUB)
		sub(run, env);
	else if (code == AND)
		and(run, env);
	else if (code == OR)
		or(run, env);
	else if (code == XOR)
		xor(run, env);
	else if (code == ZJMP)
		zjmp(run, env);
	else
	{
		ft_printf("%d not found!! Fix the code\n", code);//
	}
}
