/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:37:49 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/15 12:59:22 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

char	*read_command(char *str, int *i, int *found_command)
{
	int		len;
	int		j;
	char	*com;

	len = 0;
	j = *i;
	while (str[j] != ' ' && str[j] != '\t')
	{
		len++;
		j++;
	}
	com = (char *)malloc(sizeof(char) * len + 1);
	com[len] = '\0';
	j = 0;
	while (str[*i] != ' ' && str[*i] != '\t')
	{
		com[j] = str[*i];
		j++;
		*i = *i + 1;
	}
	*found_command = 1;
	return (com);
}

void	get_command(t_info *info, char *str, int *i, int *found_command)
{
	if (check_n_c(str) == 0)
	{
		ft_printf("Command = %s\n", read_command(str, i, found_command));
	}
	info->com = NULL;
}
