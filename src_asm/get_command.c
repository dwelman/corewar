/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:37:49 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/16 14:39:34 by daviwel          ###   ########.fr       */
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
	com[j] = '\0';
	*found_command = 1;
	return (com);
}

int		get_command(t_info *info, char *str, int *i, int *found_command)
{
	char	*command;
	char	*params;
	int		com_index;

	if (check_n_c(str) == 0)
	{
		command = read_command(str, i, found_command);
		ft_printf("Command = %s\n", command);
		if ((com_index = check_command(command, info)) == -1)
			return (-1);
		free(command);
		params = store_params(str, i);
		ft_printf("Params = %s\n", str_trim(params));
		ft_lstappend(&info->commands, create_command(params, &com_index, info));
		free(params);
	}
	info->com = NULL;
	return (0);
}
