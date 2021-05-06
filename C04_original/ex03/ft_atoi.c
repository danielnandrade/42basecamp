/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:47:06 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 22:47:08 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int sinal;
	int num;
	int neg;

	neg = 0;
	sinal = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sinal *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sinal);
}