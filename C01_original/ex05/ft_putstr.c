/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:29:48 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/04/27 09:30:52 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char *char_to_str;

	char_to_str = str;
	while (*char_to_str != 0)
	{
		write(1, char_to_str, 1);
		char_to_str++;
	}
}