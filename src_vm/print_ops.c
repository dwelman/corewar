/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 16:13:49 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/16 16:56:10 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	print_op(t_op op)
{
	char	buff[50];
	char	*ptr;
	int		i;

	i = -1;
	ptr = &buff[0];
	while (++i < op.nbr_args)
	{
		if (i)
			*ptr++ = ',';
		if ((op.type[i] & T_DIR) == T_DIR)
			ft_memcpy(ptr, " T_DIR ", 7);
		if ((op.type[i] & T_IND) == T_IND)
			ft_memcpy(ptr, " T_IND ", 7);
		if ((op.type[i] & T_REG) == T_REG)
			ft_memcpy(ptr, " T_REG ", 7);
		ptr += 6;
	}
	*ptr = '\0';
	ft_printf("%s :\n\tnbr_args = %d\n\ttype = %s\n\tcode = %d\n\tnbr_cycles \
			=%d\n", op.name, op.nbr_args, buff, op.code, op.nbr_cycles);
}

void	print_all_ops(t_op op[OP_COUNT + 1])
{
	int	i;

	i = 0;
	while (i < OP_COUNT + 1)
	{
		print_op(op[i]);
		i++;
	}
}
