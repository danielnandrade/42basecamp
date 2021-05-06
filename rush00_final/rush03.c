/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:30:06 by tjensen           #+#    #+#             */
/*   Updated: 2021/04/24 10:41:12 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(char first_sign, char middle_sign, char last_sign, int x)
{
	int count_col;

	count_col = 1;
	while (count_col <= x)
	{
		if (count_col == 1)
			ft_putchar(first_sign);
		if (count_col > 1 && count_col != x)
			ft_putchar(middle_sign);
		if (count_col == x && count_col > 1)
			ft_putchar(last_sign);
		count_col++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int count_line;

	count_line = 1;
	while (count_line <= y)
	{
		if (count_line == 1)
			ft_putline('A', 'B', 'C', x);
		if (count_line > 1 && count_line != y)
			ft_putline('B', ' ', 'B', x);
		if (count_line == y && count_line > 1)
			ft_putline('A', 'B', 'C', x);
		count_line++;
	}
}
