/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:14:56 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 21:14:57 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		*(tab + i) = min;
		min++;
		i++;
	}
	return (tab);
}