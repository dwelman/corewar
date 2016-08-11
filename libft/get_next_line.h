/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 07:44:23 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/11 11:08:22 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define B 10000

# include "libft.h"

typedef struct	s_line
{
	char	*temp;
	char	*bn;
	int		ret;
}				t_line;

int				get_next_line(const int fd, char **line);

#endif
