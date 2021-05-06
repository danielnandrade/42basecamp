/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:22:27 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:26:40 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int changer;
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = x + 1;
		while (y < size)
		{
			if (tab[y] < tab[x])
			{
				changer = tab[x];
				tab[x] = tab[y];
				tab[y] = changer;
			}
			y++;
		}
		x++;
	}
}