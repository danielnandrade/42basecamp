/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 20:57:52 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char ch_arr1[] = "daniel";
    char ch_arr2[] = "dxaniee";

	printf("%d\n", ft_strncmp(ch_arr1, ch_arr2, 5));
	printf("%d\n", strncmp(ch_arr1, ch_arr2, 5));
	return (0);
}
