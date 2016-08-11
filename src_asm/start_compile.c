/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_compile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 07:53:25 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/11 15:22:22 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	start_compile(t_info *info)
{
	int	i;

	i = 0;
	while (INPUT[i])
	{
		if (read_line(INPUT[i]) == -1)
		{
			ft_putstr_fd("Syntax error line : ", 2);
			ft_putnbr_fd(i + 1, 2);
			ft_putchar_fd('\n', 2);
		}
		i++;
	}
}
