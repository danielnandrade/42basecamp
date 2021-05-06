/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 01:47:17 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char ch_arr1[20] = "daniel";
    char ch_arr2[20] = "leticia";

    ft_strlcpy(ch_arr2, ch_arr1, 0); // copy the contents of ch_arr1 to ch_arr2

    printf("First string (ch_arr_1) = %s\n", ch_arr1);
    printf("Second string (ch_arr_2) = %s\n", ch_arr2);

	return(0);	
}
