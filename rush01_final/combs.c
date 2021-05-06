/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:29:02 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 20:35:13 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	save_combs1(int board[4][4][13], int ip_col[4][2], int i);
void	save_combs2(int board[4][4][13], int ip_col[4][2], int i);
void	save_combs3(int board[4][4][13], int ip_row[2][4], int i);
void	save_combs4(int board[4][4][13], int ip_row[2][4], int i);
void	combs(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	write_in_board(int board[4][4][13], char nbrs[5], int j, char cords[3]);

void	combs(int board[4][4][13], int ip_col[4][2], int ip_row[2][4])
{
	save_combs1(board, ip_col, 0);
	save_combs2(board, ip_col, 0);
	save_combs3(board, ip_row, 0);
	save_combs4(board, ip_row, 0);
}

void	save_combs1(int board[4][4][13], int ip_col[4][2], int i)
{
	while (i < 4)
	{
		if (ip_col[i][0] == 1 && ip_col[i][1] == 3)
		{
			write_in_board(board, "4231", i, "X1");
			write_in_board(board, "4132", i, "X2");
			write_in_board(board, "4312", i, "X3");
		}
		else if (ip_col[i][0] == 3 && ip_col[i][1] == 1)
		{
			write_in_board(board, "1324", i, "X1");
			write_in_board(board, "2314", i, "X2");
			write_in_board(board, "2134", i, "X3");
		}
		else if (ip_col[i][0] == 1 && ip_col[i][1] == 2)
		{
			write_in_board(board, "4123", i, "X1");
			write_in_board(board, "4213", i, "X2");
		}
		else if (ip_col[i][0] == 2 && ip_col[i][1] == 1)
			write_in_board(board, "3214", i, "X1");
		if (ip_col[i][0] == 2 && ip_col[i][1] == 1)
			write_in_board(board, "3124", i, "X2");
		i++;
	}
}

void	save_combs2(int board[4][4][13], int ip_col[4][2], int i)
{
	while (i < 4)
	{
		if (ip_col[i][0] == 3 && ip_col[i][1] == 2)
		{
			write_in_board(board, "1243", i, "X1");
			write_in_board(board, "1342", i, "X2");
			write_in_board(board, "2341", i, "X3");
		}
		else if (ip_col[i][0] == 2 && ip_col[i][1] == 3)
		{
			write_in_board(board, "3421", i, "X1");
			write_in_board(board, "2431", i, "X2");
			write_in_board(board, "1432", i, "X3");
		}
		else if (ip_col[i][0] == 2 && ip_col[i][1] == 2)
		{
			write_in_board(board, "3412", i, "X1");
			write_in_board(board, "2413", i, "X2");
			write_in_board(board, "1423", i, "X3");
			write_in_board(board, "2143", i, "X4");
			write_in_board(board, "3142", i, "X5");
			write_in_board(board, "3241", i, "X6");
		}
		i++;
	}
}

void	save_combs3(int board[4][4][13], int ip_row[2][4], int i)
{
	while (i < 4)
	{
		if (ip_row[0][i] == 1 && ip_row[1][i] == 3)
		{
			write_in_board(board, "4231", i, "Y7");
			write_in_board(board, "4132", i, "Y8");
			write_in_board(board, "4312", i, "Y9");
		}
		else if (ip_row[0][i] == 3 && ip_row[1][i] == 1)
		{
			write_in_board(board, "1324", i, "Y7");
			write_in_board(board, "2314", i, "Y8");
			write_in_board(board, "2134", i, "Y9");
		}
		else if (ip_row[0][i] == 1 && ip_row[1][i] == 2)
		{
			write_in_board(board, "4123", i, "Y7");
			write_in_board(board, "4213", i, "Y8");
		}
		else if (ip_row[0][i] == 2 && ip_row[1][i] == 1)
			write_in_board(board, "3214", i, "Y7");
		if (ip_row[0][i] == 2 && ip_row[1][i] == 1)
			write_in_board(board, "3124", i, "Y8");
		i++;
	}
}

void	save_combs4(int board[4][4][13], int ip_row[2][4], int i)
{
	while (i < 4)
	{
		if (ip_row[0][i] == 3 && ip_row[1][i] == 2)
		{
			write_in_board(board, "1243", i, "Y7");
			write_in_board(board, "1342", i, "Y8");
			write_in_board(board, "2341", i, "Y9");
		}
		else if (ip_row[0][i] == 2 && ip_row[1][i] == 3)
		{
			write_in_board(board, "3421", i, "Y7");
			write_in_board(board, "2431", i, "Y8");
			write_in_board(board, "1432", i, "Y9");
		}
		else if (ip_row[0][i] == 2 && ip_row[1][i] == 2)
		{
			write_in_board(board, "3412", i, "Y7");
			write_in_board(board, "2413", i, "Y8");
			write_in_board(board, "1423", i, "Y9");
			write_in_board(board, "2143", i, "Y;");
			write_in_board(board, "3142", i, "Y:");
			write_in_board(board, "3241", i, "Y<");
		}
		i++;
	}
}
