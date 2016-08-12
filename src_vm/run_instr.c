/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 09:21:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/12 09:25:47 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm>

/*
** Runs the correct function depending on given t_op_run struct.
*/

void	run_instr(t_op_run *run, t_env *env)
{
	int	code;

	code = run->op;
	ft_printf("Looking for op %d\n", code);
	if (code == LIVE)
		live(run, env);
	else
		ft_printf("%d not found!!\n", code);
}
