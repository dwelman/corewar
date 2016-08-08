/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 11:35:08 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/06 11:45:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	reverse_bytes(void *mem, size_t size)
{
	int		i;
	int		j;
	void	*temp;
	char	*ptr;

	i = size - 1;
	j = 0;
	ptr = (char*)mem;
	temp = malloc(size);
	while (i)
	{
		temp[j] = *ptr[i];
		j++;
		i--;
	}
	free(temp);
}
