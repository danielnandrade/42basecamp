/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:10:05 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 13:43:48 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int aux;

	if (index > 1)
	{
		aux = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (aux);
	}
	else if (index == 1)
		return (1);
	else if (index == 0)
		return (0);
	else
		return (-1);
}
