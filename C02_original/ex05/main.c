/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 01:31:28 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_str_is_uppercase(char *str);

int	main(void)
{
	char ch_arr1[20] = "AAAA";
	int b = 0;

	b =  ft_str_is_uppercase(ch_arr1);

	printf("Check alpha string (ch_arr_1) = %d\n", b);

	return(0);	
}
