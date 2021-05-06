/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_col_variation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:43:24 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 23:32:23 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	branch_col_variation(int board[4][4][13], int board_bu[4][4][13]);
int		bran_p2(int board[4][4][13], int board_bu[4][4][13], int var[5], int x);
int		bran_p3(int board[4][4][13], int board_bu[4][4][13], int x, int z);
void	bran_p4(int board[4][4][13], int board_bu[4][4][13], int x, int z);

void	bran_p4(int board[4][4][13], int board_bu[4][4][13], int x, int z)
{
	board[x][0][z] = 0;
	board[x][1][z] = 0;
	board[x][2][z] = 0;
	board[x][3][z] = 0;
	board_bu[x][0][z] = 0;
	board_bu[x][1][z] = 0;
	board_bu[x][2][z] = 0;
	board_bu[x][3][z] = 0;
}

int		bran_p3(int board[4][4][13], int board_bu[4][4][13], int x, int z)
{
	board[x][0][0] = board[x][0][z];
	board[x][1][0] = board[x][1][z];
	board[x][2][0] = board[x][2][z];
	board[x][3][0] = board[x][3][z];
	board[x][0][z] = 0;
	board[x][1][z] = 0;
	board[x][2][z] = 0;
	board[x][3][z] = 0;
	board_bu[x][0][z] = 0;
	board_bu[x][1][z] = 0;
	board_bu[x][2][z] = 0;
	board_bu[x][3][z] = 0;
	return (1);
}

int		bran_p2(int board[4][4][13], int board_bu[4][4][13], int var[5], int x)
{
	while (var[0] < 4)
	{
		var[2] = 0;
		var[1] = 7;
		while (var[1] < 13)
		{
			if (board[x][var[0]][var[1]] != 0 &&
				board[x][var[0]][var[1]] == board[x][var[0]][var[4]])
			{
				var[3] += 1;
				break ;
			}
			else if (board[x][var[0]][var[1]] == 0)
				var[2] += 1;
			var[1] += 1;
		}
		if (var[2] == 6)
			var[3] += 1;
		var[0] += 1;
	}
	if (var[3] == 4)
		return (bran_p3(board, board_bu, x, var[4]));
	else
		bran_p4(board, board_bu, x, var[4]);
	return (0);
}

void	branch_col_variation(int board[4][4][13], int board_bu[4][4][13])
{
	int x;
	int z;
	int var[5];

	x = 0;
	while (x < 4)
	{
		z = 1;
		while (z < 7)
		{
			if (board[x][0][z] != 0)
			{
				var[0] = 0;
				var[1] = 7;
				var[2] = 0;
				var[3] = 0;
				var[4] = z;
				if (bran_p2(board, board_bu, var, x) == 1)
					return ;
			}
			z++;
		}
		x++;
	}
}
