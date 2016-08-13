/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 09:21:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/13 12:54:52 by ddu-toit         ###   ########.fr       */
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
	else if (code == ZJMP)
		zjmp(run, env);
	else
	{
		ft_printf("%d not found!! Fix the code\n", code);
	}
}
