/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 08:32:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/11 11:07:46 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_line(int const fd, char **stock)
{
	char	*buff;
	int		ret;
	char	*temp;

	if (!(buff = ft_strnew(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(*stock, buff);
		free(*stock);
		*stock = temp;
	}
	free(buff);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char		*s = NULL;
	t_line			l;

	if ((!s && (s = ft_strnew(sizeof(*s))) == NULL) || !line || fd < 0 || B < 0)
		return (-1);
	l.bn = ft_strchr(s, '\n');
	while (l.bn == NULL)
	{
		l.ret = read_line(fd, &s);
		if (l.ret == 0)
		{
			if (ft_strlen(s) == 0)
				return (0);
			s = ft_strjoin(s, "\n");
		}
		if (l.ret < 0)
			return (-1);
		else
			l.bn = ft_strchr(s, '\n');
	}
	*line = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(l.bn));
	l.temp = s;
	s = ft_strdup(l.bn + 1);
	free(l.temp);
	return (1);
}
