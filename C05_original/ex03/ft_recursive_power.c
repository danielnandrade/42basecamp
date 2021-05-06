/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:09:18 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 16:32:55 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int num;

	num = nb;
	// if (num > num * nb)
	// 	return (0);
	if (power > 1)
		return (num * ft_recursive_power(num, power - 1));
	else if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (num);
}
