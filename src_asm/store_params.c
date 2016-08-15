/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:40:18 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/15 14:53:36 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

char	*store_params(char *str, int *i)
{
	int		len;
	int		j;
	char	*ret;
	
	j = *i;
	len = 0;
	while (str[j] != '\0' && str[j] != COMMENT_CHAR)
	{
		len++;
		j++;
	}
	j = 0;
	ret = (char *)malloc(sizeof(char) * len + 1);
	while (str[*i] != '\0' && str[*i] != COMMENT_CHAR)
	{
		ret[j] = str[*i];
		j++;
		*i = *i + 1;
	}
	ret[j] = '\0';
	return (ret);
}
