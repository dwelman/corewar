/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:06:29 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/16 15:02:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

int		count_param_bytes(char **params, int num, BOOL dir_as_index)
{
	int	i;
	int	count;
	int	param_type;

	i = 0;
	count = 0;
	while (i < num)
	{ 
		param_type = check_param(params[i]);
		if (param_type == REG_CODE)
			count += 1;
		else if (param_type == IND_CODE)
			count += IND_SIZE;
		else
		{
			if (dir_as_index == TRUE)
				count += IND_SIZE;
			else
				count += REG_SIZE;
		}
		i++;
	}
	return (count);
}

char	*get_param_bytes(char **params, int num, t_command *nc, t_info *info)
{
	int		i;
	int		param_type;
	//int		temp;
	//short	s_temp;
	char	*ret;

	i = 0;
	nc->command_bytes = count_param_bytes(params, num, nc->dir_as_index);
	ret = (char *)malloc(nc->command_bytes + 1);
	while (i < num)
	{
		param_type = check_param(params[i]);
		if (param_type == REG_CODE)
		{
			if (nc->dir_as_index == TRUE)
			{

			}
		}
		
		i++;
	}
	info->com = NULL;
	return (NULL);
}
