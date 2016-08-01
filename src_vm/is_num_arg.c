/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 11:35:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/29 11:38:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static long int	ft_atoi_long(const char *str)
{
	int			i;
	int			min;
	long int	total;

	i = 0;
	min = 1;
	total = 0;
	if (str[0] == '-')
	{
		min = -1;
		str++;
	}
	while (ft_isdigit(str[i]))
		total = total * 10 + (str[i++] - '0');
	return (min * total);
}

int				check_int(char *arg)
{
	long int	ret;

	ret = ft_atoi_long(arg);
	if (ret <= 2147483647 && ret >= -2147483648)
		return ((int)ret);
	else
		error_print();
	return (ret);
}

static int		is_numeric(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (0);
	if (arg[i] && arg[i] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void			error_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		error_print();
	while (i < argc)
	{
		if (is_numeric(argv[i]) == 0)
			error_print();
		i++;
	}
}
