/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:29:42 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/11 15:22:20 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

int	check_label_char(char c)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			in = 1;
		i++;
	}
	if (in == 1)
		return (1);
	else
		return (-1);
}

int	check_label(char *line, int i)
{
	int		j;
	char	*label;

	j = i - 1;
	if (i == 0)
		return (-1);
	if (line[i - 1] == DIRECT_CHAR)
	{
		ft_printf("Direct : %s\n", line);
	}
	else
	{
		while (j >= 0)
		{
			if (check_label_char(line[j]) == -1)
				return (-1);
			j--;
		}
		label = (char *)malloc(sizeof(char *) * i + 2);
		while (j < i)
		{
			label[j] = line[j];
			j++;
		}
		ft_printf("label : %s\n", label);
	}
	return (0);
}
