/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 08:25:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:16:46 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Counts the elements in an array
*/

int	count_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
