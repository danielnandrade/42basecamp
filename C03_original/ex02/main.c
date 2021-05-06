/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 21:11:34 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char ch_arr1[] = "daniel";
    char ch_arr2[] = "andrade";

	printf("%s\n", ft_strcat(ch_arr1, ch_arr2));
	printf("%s\n", strcat(ch_arr1, ch_arr2));
	return (0);
}
