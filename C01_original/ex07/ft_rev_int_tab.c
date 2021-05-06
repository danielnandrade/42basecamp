/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:11:57 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:20:06 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int counter;
	int changer;

	counter = 0;
	while (counter < size)
	{
		changer = tab[counter];
		tab[counter] = tab[size - 1];
		tab[size - 1] = changer;
		counter++;
		size--;
	}
}
