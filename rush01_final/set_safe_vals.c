/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_safe_vals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:29:21 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 20:42:10 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	vals1(int board[4][4][13], int ip_col[4][2], int ip_row[2][4], int i);
void	vals2(int board[4][4][13], int ip_col[4][2], int ip_row[2][4], int i);
void	vals3(int board[4][4][13], int ip_row[2][4], int i);
void	vals4(int board[4][4][13], int ip_col[4][2], int ip_row[2][4], int i);
void	set_safe_vals(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	write_in_board(int board[4][4][13], char nbrs[5], int j, char cords[3]);

void	set_safe_vals(int board[4][4][13], int ip_col[4][2], int ip_row[2][4])
{
	vals1(board, ip_col, ip_row, 0);
	vals2(board, ip_col, ip_row, 0);
	vals3(board, ip_row, 0);
	vals4(board, ip_col, ip_row, 0);
}

void	vals1(int board[4][4][13], int ip_col[4][2], int ip_row[2][4], int i)
{
	while (i < 4)
	{
		if (ip_col[i][0] == 4 && ip_col[i][1] == 1)
			write_in_board(board, "1234", i, "X0");
		else if (ip_col[i][0] == 1 && ip_col[i][1] == 4)
			write_in_board(board, "4321", i, "X0");
		if (ip_row[0][i] == 4 && ip_row[1][i] == 1)
			write_in_board(board, "1234", i, "Y0");
		else if (ip_row[0][i] == 1 && ip_row[1][i] == 4)
			write_in_board(board, "4321", i, "Y0");
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (ip_col[i][0] == 1)
			board[i][0][0] = 4;
		else if (ip_col[i][1] == 1)
			board[i][3][0] = 4;
		if (ip_row[0][i] == 1)
			board[0][i][0] = 4;
		else if (ip_row[1][i] == 1)
			board[3][i][0] = 4;
		i++;
	}
}

void	vals2(int board[4][4][13], int ip_col[4][2], int ip_row[2][4], int i)
{
	while (i < 4)
	{
		if (ip_col[i][0] == 3 && board[i][3][0] == 3 && board[i][2][0]
			== board[i][1][0] && board[i][0][0] == 0)
		{
			board[i][2][0] = 4;
			board[i][1][0] = 2;
			board[i][0][0] = 1;
		}
		if (ip_col[i][1] == 3 && board[i][0][0] == 3 && board[i][1][0]
			== board[i][2][0] && board[i][3][0] == 0)
		{
			board[i][1][0] = 4;
			board[i][2][0] = 2;
			board[i][3][0] = 1;
		}
		if (ip_row[0][i] == 3 && board[3][i][0] == 3 && board[2][i][0]
			== board[1][i][0] && board[0][i][0] == 0)
		{
			board[2][i][0] = 4;
			board[1][i][0] = 2;
			board[0][i][0] = 1;
		}
		i++;
	}
}

void	vals3(int board[4][4][13], int ip_row[2][4], int i)
{
	while (i < 4)
	{
		if (ip_row[1][i] == 3 && board[0][i][0] == 3 && board[1][i][0]
				== board[2][i][0] && board[3][i][0] == 0)
		{
			board[1][i][0] = 4;
			board[2][i][0] = 2;
			board[3][i][0] = 1;
		}
		if (ip_row[0][i] == 3 && board[3][i][0] == 3 && board[2][i][0]
			== board[1][i][0] && board[0][i][0] == 0)
		{
			board[2][i][0] = 4;
			board[1][i][0] = 2;
			board[0][i][0] = 1;
		}
		if (ip_row[1][i] == 3 && board[0][i][0] == 3 && board[1][i][0]
				== board[2][i][0] && board[3][i][0] == 0)
		{
			board[1][i][0] = 4;
			board[2][i][0] = 2;
			board[3][i][0] = 1;
		}
		i++;
	}
}

void	vals4(int board[4][4][13], int ip_col[4][2], int ip_row[2][4], int i)
{
	while (i < 4)
	{
		if (ip_col[i][0] == 2 && ip_col[i][1] == 1)
			board[i][0][0] = 3;
		if (ip_col[i][1] == 2 && ip_col[i][0] == 1)
			board[i][3][0] = 3;
		if (ip_row[0][i] == 2 && ip_row[1][i] == 1)
			board[0][i][0] = 3;
		if (ip_row[1][i] == 2 && ip_row[0][i] == 1)
			board[3][i][0] = 3;
		i++;
	}
}
