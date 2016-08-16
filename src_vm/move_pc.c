/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:22:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/16 16:13:28 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Function to move pc by offset bytes in a circular manner.
*/

void	move_pc(t_cpu *p, int offset, t_env *env)
{
	while (offset > MEM_SIZE * 2)
		offset -= MEM_SIZE;
	if (p->pc + offset > env->memory + MEM_SIZE)
	{
		offset -= p->pc + offset - (env->memory + MEM_SIZE);
		p->pc = &env->memory[offset];
	}
	else
		p->pc += offset;
}
