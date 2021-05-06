/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:14:41 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 21:14:43 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	char	*charptr;
	int		iterator;

	charptr = str;
	iterator = 0;
	while (*charptr != 0)
	{
		iterator++;
		charptr++;
	}
	return (iterator);
}

char	*ft_strdup(char *src)
{
	char	*dupli;
	int		i;

	i = 0;
	if (!(dupli = malloc(ft_strlen(src) + 1)))
		return (dupli);
	while (src[i])
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = 0;
	return (dupli);
}