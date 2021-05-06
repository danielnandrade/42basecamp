/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_1_sol_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:44:56 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 22:45:21 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_for_1_sol_left_cols(int board[4][4][13], int x, int y, int z);
void	check_for_1_sol_left_cols_pt2(int board[4][4][13], int x, int z_sol);
void	check_for_1_sol_left_rows(int board[4][4][13], int x, int y, int z);
void	check_for_1_sol_left_rows_pt2(int board[4][4][13], int y, int z_sol);

void	check_for_1_sol_left_cols(int board[4][4][13], int x, int y, int z)
{
	int z_sol;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z_sol = 0;
			z = 1;
			while (z < 7)
			{
				if (board[x][y][z] != 0 && z_sol == 0)
					z_sol = z;
				else if (board[x][y][z] != 0 && z_sol != 0)
					z_sol = -1;
				z++;
			}
			if (z_sol != 0 && z_sol != -1)
				check_for_1_sol_left_cols_pt2(board, x, z_sol);
			y++;
		}
		x++;
	}
}

void	check_for_1_sol_left_cols_pt2(int board[4][4][13], int x, int z_sol)
{
	board[x][0][0] = board[x][0][z_sol];
	board[x][1][0] = board[x][1][z_sol];
	board[x][2][0] = board[x][2][z_sol];
	board[x][3][0] = board[x][3][z_sol];
}

void	check_for_1_sol_left_rows(int board[4][4][13], int x, int y, int z)
{
	int z_sol;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z_sol = 0;
			z = 7;
			while (z < 13)
			{
				if (board[x][y][z] != 0 && z_sol == 0)
					z_sol = z;
				else if (board[x][y][z] != 0 && z_sol != 0)
					z_sol = -1;
				z++;
			}
			if (z_sol != 0 && z_sol != -1)
				check_for_1_sol_left_rows_pt2(board, y, z_sol);
			y++;
		}
		x++;
	}
}

void	check_for_1_sol_left_rows_pt2(int board[4][4][13], int y, int z_sol)
{
	board[0][y][0] = board[0][y][z_sol];
	board[1][y][0] = board[1][y][z_sol];
	board[2][y][0] = board[2][y][z_sol];
	board[3][y][0] = board[3][y][z_sol];
}
