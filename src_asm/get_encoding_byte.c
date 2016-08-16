/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_encoding_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 08:42:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/16 11:33:38 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	encode_byte(char *byte, char *param)
{
	int	par_type;

	if ((par_type = check_param(param)) == T_DIR)
	{
		*byte = *byte << 1;
		*byte += 1;
		*byte = *byte << 1;
		*byte += 0;
	}
	else if (par_type == T_REG)
	{
		*byte = *byte << 1;
		*byte += 0;
		*byte = *byte << 1;
		*byte += 1;
	}
	else if (par_type == T_IND)
	{
		*byte = *byte << 1;
		*byte += 1;
		*byte = *byte << 1;
		*byte += 1;
	}
}

char	get_encoding_byte(char **params, int num, int op_index, t_info *info)
{
	char	byte;
	int		i;

	byte = 0;
	i = 0;
	if (num != info->op_tab[op_index].nbr_args)
	{
		byte = '\0';
		return (byte);
	}
	while (i < 4)
	{
		if (i < num)
			encode_byte(&byte, params[i]);
		else
			byte = byte << 2;
		i++;
	}
	print_memory(&byte, 1);
	return (byte);
}
