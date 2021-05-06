/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:06:11 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/02 17:12:08 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_verify(int counts, char *values);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_continue_verify_numbers(char *values);
int		ft_verify_numbers(char *values, int i);
int		ft_continue_verify(char *values,int i);
void	ft_logic_start(char *values);
void	populate_matrix_up(char *values, int ***matrix);
void	populate_matrix_do(char *values, int ***matrix);
void	populate_matrix_le(char *values, int ***matrix);
void	populate_matrix_ri(char *values, int ***matrix);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}