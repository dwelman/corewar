/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:59:13 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/06 11:34:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int	ft_hex_to_int(char *hex)
{
 	int			i;
	int			j;

	i = ft_strlen(hex);
	ft_printf("i = %d\n", i);
	ret = 0;
	while (i)
	{

		ft_printf("temp = %d\n", temp);
		ret = ret * 16 + (temp);
		ft_printf("ret = %d\n", ret);
		i--;
	}
	return (ret);
}
