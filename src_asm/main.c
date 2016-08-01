/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:55:31 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/01 12:36:26 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		i; //////////////

	i = 0;
	if (error_check(argc, argv) == -1)
		return (0);
	store_input(&info, argv[1]);
	while (info.input[i])
	{
		ft_putstr(info.input[i]);
		free(info.input[i]);
		ft_putchar('\n');
		i++;
	}
	free(info.input);
}