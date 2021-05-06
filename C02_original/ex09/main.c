/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:26:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/05 01:39:23 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_alpha(char c);
char	ft_upcase(char c);
char	ft_lowcase(char c);
char	*ft_strcapitalize(char *str);

int	main(void)
{
	char ch_arr1[20] = "hallo, alles gut ?";
 

    ft_strcapitalize(ch_arr1);

    printf("First string (ch_arr_1) = %s\n", ch_arr1);

	return(0);	
}
