/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:37:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/09 14:55:45 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Clears temp op structs to be reused.
*/

void		clear_op(t_op_run *op, t_env *env)
{
	int	i;

	i = 0;
	ft_memdel((void**)&op->arg_types);
	ft_memdel((void**)&op->arg_sizes);
	while (i < OP(op->op).nbr_args)
	{
		if (op->arg[i])
			free(op->arg[i]);
		i++;
	}
	ft_memdel((void**)&op->arg);
	op->reset = TRUE;
}

void		print_oprun(t_op_run op, t_env *env)//debug
{
	
	ft_printf("op : %s\n to_exec %d\n player = %d\n" , OP(op.op).name, op.to_exec, op.player);
	int	i = 0;
	ft_printf("types : \n");
	while (i < OP(op.op).nbr_args)
	{
		ft_printf("%d ", op.arg_types[i]);
		i++;	
	}
	i = 0;
	ft_printf("\nsizes : \n");
	while (i < OP(op.op).nbr_args)
	{
		ft_printf("%d ", op.arg_sizes[i]);
		i++;	
	}
	i = 0;
	ft_printf("\nargs : \n");
	while (i < OP(op.op).nbr_args)
	{
		print_memory(op.arg[i], op.arg_sizes[i]);
		i++;
	}
}

/*
** Gets arguments  assumes encoding byte has been skipped
*/

void		get_args(t_op_run *new, t_env *env, char *pc)
{
	int		i;

	i = 0;
	new->arg = (char**)malloc(sizeof(char*) * MAX_ARGS_NUMBER);
	while (i < MAX_ARGS_NUMBER)
	{
		if (i < OP(new->op).nbr_args)
		{
			new->arg[i] = cload_bytes(pc, MEM_SIZE, new->arg_sizes[i]);
			pc += new->arg_sizes[i];
		}
		else
			new->arg[i] = NULL;
		i++;
	}
}

/*
** Sets values for struct t_op_run.
*/

t_op_run	load_op(t_cor player, t_env *env)
{
	t_op_run	new;
	int			op;
	char		*pc;

	op = (int)*player.cpu.pc;
	pc = player.cpu.pc;
	new.to_exec = OP(op).nbr_cycles;
	new.op = (int)*pc++;
	if (OP(op).n_byte == FALSE)
		new.arg_types = no_n_byte();
	else
		new.arg_types = get_arg_types(pc++);
	new.reset = FALSE;
	new.player = player.p_num;
	new.arg_sizes = get_arg_sizes(&new, env);
	get_args(&new, env, pc);	
	print_oprun(new, env);
	return (new);
}
