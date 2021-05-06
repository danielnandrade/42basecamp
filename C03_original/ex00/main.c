/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 20:55:12 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <string.h>

int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char ch_arr1[] = "daniel";
    char ch_arr2[] = "daniee";

	printf("%d\n", ft_strcmp(ch_arr1, ch_arr2));
	printf("%d\n", strcmp(ch_arr1, ch_arr2));
	return (0);
}
