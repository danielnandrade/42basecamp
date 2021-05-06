/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:47:56 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 22:54:09 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	copy_cube(int board[4][4][13], int board_bu[4][4][13]);
void	write_in_board(int board[4][4][13], char nbrs[5], int j, char cords[3]);
int		assign_input(int ip_col[4][2], int ip_row[2][4], char *argv[]);
void	zero_board(int board[4][4][13]);
void	print_board(int board[4][4][13], int layer);

void	copy_cube(int board[4][4][13], int board_bu[4][4][13])
{
	int x;
	int y;
	int z;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z = 0;
			while (z < 13)
			{
				board_bu[x][y][z] = board[x][y][z];
				z++;
			}
			y++;
		}
		x++;
	}
}

void	write_in_board(int board[4][4][13], char nbrs[5], int i, char cords[3])
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (cords[0] == 'X')
			board[i][j][cords[1] - 48] = nbrs[j] - 48;
		if (cords[0] == 'Y')
			board[j][i][cords[1] - 48] = nbrs[j] - 48;
		j++;
	}
}

int		assign_input(int ip_col[4][2], int ip_row[2][4], char *argv[])
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (argv[1][i * 2] < '1' || argv[1][i * 2] > '4')
			return (-1);
		if (i != 0 && argv[1][i * 2 - 1] != ' ')
			return (-1);
		if (i == 15 && argv[1][i * 2 + 1] != '\0')
			return (-1);
		if (i < 4)
			ip_col[i][0] = argv[1][i * 2] - 48;
		else if (i < 8)
			ip_col[i - 4][1] = argv[1][i * 2] - 48;
		else if (i < 12)
			ip_row[0][i - 8] = argv[1][i * 2] - 48;
		else if (i < 16)
			ip_row[1][i - 12] = argv[1][i * 2] - 48;
		i++;
	}
	return (0);
}

void	zero_board(int board[4][4][13])
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 13)
			{
				board[i][j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	print_board(int board[4][4][13], int layer)
{
	int		i;
	int		j;
	char	to_print;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			to_print = board[j][i][layer] + 48;
			write(1, &to_print, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
