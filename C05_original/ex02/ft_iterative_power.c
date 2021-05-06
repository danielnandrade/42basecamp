/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:09:18 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 13:43:32 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		res *= nb;
	return (res);
}
