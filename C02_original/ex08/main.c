/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 01:36:41 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char ch_arr1[20] = "DANIEL";
 

    ft_strlowcase(ch_arr1);

    printf("First string (ch_arr_1) = %s\n", ch_arr1);

	return(0);	
}
