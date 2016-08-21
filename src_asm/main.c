/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:55:31 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/21 16:25:44 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		i; //////////////

	i = 0;
	info.commands = NULL;
	if (error_check(argc, argv) == -1)
		return (0);
	info.file_name = argv[1];
	store_input(&info, argv[1]);
	validate_input(&info);
	start_compile(&info);
	write_file(&info);
	//SHould do all freeing in a seperate function
	while (info.input[i])
	{
		//ft_putstr(info.input[i]);
		free(info.input[i]);
		//ft_putchar('\n');
		i++;
	}
	free(info.input);
	free_info_label(&info);
}
