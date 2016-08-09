/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:37:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/09 12:52:48 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int			*get_arg_types(char *e_byte)
{
	int	*arg_types;
	int	i;
	int	temp;

	arg_types = (int*)malloc(sizeof(int) * 4);
	i = 0;
	while (i < 4)
	{
		temp = *(int*)e_byte;
		arg_types[i] = (temp >> (6 - (i * 2))) & 3;
		i++;
	}
	return (arg_types);
}

int			arg_size(int arg_type)
{
	if (arg_type == REG_CODE)
		return (REG_SIZE);
	if (arg_type == DIR_CODE)
		return (DIR_SIZE);
	if (arg_type == IND_CODE)
		return (IND_SIZE);
	return (0);
}

void		clear_op(t_op_run *op, t_env *env)
{
	int	i;

	i = 0;
	ft_memdel((void**)&op->arg_types);
	while (i < OP(op->op).nbr_args)
	{
		if (op->arg[i])
			free(op->arg[i]);

		i++;
	}
	ft_memdel((void**)&op->arg);
	op->reset = TRUE;
}

t_op_run	load_op(t_cor player, t_env *env)
{
	t_op_run	new;
	int			i;
	int			op;
	char		*pc;

	op = (int)*player.cpu.pc;
	pc = player.cpu.pc;
	new.to_exec = OP(op).nbr_cycles;
	new.op = (int)*pc++;
	new.arg_types = get_arg_types(pc++);
	new.reset = FALSE;
	new.player = player.p_num;
	new.arg = (char**)malloc(sizeof(char*) * MAX_ARGS_NUMBER);
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (i < OP(op).nbr_args)

			new.arg[i] = cload_bytes(pc, MEM_SIZE, arg_size(new.arg_types[i]));
		else
			new.arg[i] = NULL;
		i++;
	}
	return (new);
}
