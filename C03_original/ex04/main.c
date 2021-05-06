/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 06:12:48 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char ch_arr1[] = "daniel";
    char ch_arr2[] = "ni";

	printf("%s\n", ft_strstr(ch_arr1, ch_arr2));
	// printf("%s\n", strstr(ch_arr1, ch_arr2));
	return (0);
}
