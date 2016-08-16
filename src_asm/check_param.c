/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 09:12:12 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/16 10:45:07 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Returns the type of parameter
*/

int	check_param(char *param)
{
	if (param[1] == DIRECT_CHAR)
		return (DIR_CODE);
	else if (param[1] == 'r')
		return (REG_CODE);
	else
		return (IND_CODE);
}
