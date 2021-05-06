/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:49:21 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 22:50:10 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_for_valid_board(int board[4][4][13]);
int		check_for_valid_board_pt2(int board[4][4][13], int v[3], int x, int y);
void	erase_conflicting_rows(int board[4][4][13], int x);
void	erase_conflicting_cols(int board[4][4][13], int x);
void	stamp_duplicates(int board[4][4][13], int variables[3], int x, int y);

int		check_for_valid_board(int board[4][4][13])
{
	int v[3];

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	return (check_for_valid_board_pt2(board, v, 0, 0));
}

int		check_for_valid_board_pt2(int board[4][4][13], int v[3], int x, int y)
{
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			v[2] += board[x][y][0];
			v[0] = x;
			while (v[0] < 4)
			{
				if (board[x][y][0] == board[v[0]][y][0] && x != v[0])
					return (-1);
				v[0] += 1;
			}
			v[1] = y;
			while (v[1] < 4)
			{
				if (board[x][y][0] == board[x][v[1]][0] && y != v[1])
					return (-1);
				v[1] += 1;
			}
			y += 1;
		}
		x += 1;
	}
	return (v[2]);
}

void	erase_conflicting_rows(int board[4][4][13], int x)
{
	int y;
	int z;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z = 7;
			while (z < 13)
			{
				if (board[x][y][0] != 0 && board[x][y][z] != board[x][y][0])
				{
					board[0][y][z] = 0;
					board[1][y][z] = 0;
					board[2][y][z] = 0;
					board[3][y][z] = 0;
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

void	erase_conflicting_cols(int board[4][4][13], int x)
{
	int y;
	int z;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z = 1;
			while (z < 7)
			{
				if (board[x][y][0] != 0 && board[x][y][z] != board[x][y][0])
				{
					board[x][0][z] = 0;
					board[x][1][z] = 0;
					board[x][2][z] = 0;
					board[x][3][z] = 0;
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

void	stamp_duplicates(int board[4][4][13], int variables[3], int x, int y)
{
	int z;
	int tmp;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			variables[2] = 0;
			tmp = 0;
			z = variables[0];
			while (z <= variables[1])
			{
				if (board[x][y][z] != 0 && tmp == 0)
					tmp = board[x][y][z];
				else if (board[x][y][z] != 0 && tmp != board[x][y][z])
					variables[2] = -1;
				z++;
			}
			if (variables[2] == 0 && tmp != 0 && board[x][y][0] == 0)
				board[x][y][0] = tmp;
			y++;
		}
		x++;
	}
}
