/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:27:15 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/09 12:25:09 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Function that loads bytes (in malloc'd char array) from an array as if the array is circular.
*/

char	*cload_bytes(char *ptr, size_t block_size, size_t bytes)
{
	char		*ret;
	size_t		i;
	size_t		b;

	if (bytes)
		ret = (char*)malloc(sizeof(char) * bytes);
	else
		return (NULL);
	i = 0;
	b = 0;
	while (b < bytes)
	{
		if (i >= block_size)
			i = 0;
		ret[b++] = ptr[i++];
	}
	return (ret);
}
