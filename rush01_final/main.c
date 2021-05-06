/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittecz <mwittecz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 19:04:22 by mwittecz          #+#    #+#             */
/*   Updated: 2021/05/02 23:40:52 by mwittecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		assign_input(int ip_col[4][2], int ip_row[2][4], char *argv[]);
void	zero_board(int board[4][4][13]);
void	print_board(int board[4][4][13], int layer);
void	write_in_board(int board[4][4][13], char nbrs[5], int j, char cords[3]);
void	stamp_duplicates(int board[4][4][13], int variables[3], int x, int y);
void	erase_conflicting_rows(int board[4][4][13], int x);
void	erase_conflicting_cols(int board[4][4][13], int x);
void	perform_algorithm(int board[4][4][13]);
int		check_for_valid_board(int board[4][4][13]);
void	copy_cube(int board[4][4][13], int board_bu[4][4][13]);
void	main2(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	combs(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	check_for_3_in_4_p1(int board[4][4][13], int i, int j);
void	check_for_3_in_4_p2(int board[4][4][13], int i, int j);
void	set_safe_vals(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	check_for_1_sol_left_cols(int board[4][4][13], int x, int y, int z);
void	check_for_1_sol_left_rows(int board[4][4][13], int x, int y, int z);
void	branch_col_variation(int board[4][4][13], int board_bu[4][4][13]);

void	main2(int board[4][4][13], int ip_col[4][2], int ip_row[2][4])
{
	int board_bu[4][4][13];
	int board_bu2[4][4][13];
	int i;

	zero_board(board);
	set_safe_vals(board, ip_col, ip_row);
	combs(board, ip_col, ip_row);
	perform_algorithm(board);

	i = 0;
	while (i < 8)
	{
		if (check_for_valid_board(board) == -1)
		{
			copy_cube(board, board_bu);
			copy_cube(board, board_bu2);
			branch_col_variation(board, board_bu);
			perform_algorithm(board);
			if (check_for_valid_board(board) == -1)
			{
				branch_col_variation(board, board_bu);
				perform_algorithm(board);
				if (check_for_valid_board(board) == -1)
					copy_cube(board_bu, board);
			}
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int ip_col[4][2];
	int ip_row[2][4];
	int board[4][4][13];

	if (assign_input(ip_col, ip_row, argv) == -1 || argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	main2(board, ip_col, ip_row);
	if (check_for_valid_board(board) == 40)
		print_board(board, 0);
	else
		write(1, "Error\n", 6);
}

void	perform_algorithm(int board[4][4][13])
{
	int i;
	int variables1[3];
	int variables2[3];

	variables1[0] = 1;
	variables1[1] = 6;
	variables1[2] = 0;
	variables2[0] = 7;
	variables2[1] = 12;
	variables2[2] = 0;
	i = 0;
	while (i < 8)
	{
		stamp_duplicates(board, variables1, 0, 0);
		stamp_duplicates(board, variables2, 0, 0);
		erase_conflicting_cols(board, 0);
		erase_conflicting_rows(board, 0);
		check_for_1_sol_left_cols(board, 0, 0, 1);
		check_for_1_sol_left_rows(board, 0, 0, 7);
		check_for_3_in_4_p1(board, 0, 0);
		check_for_3_in_4_p2(board, 0, 0);
		i++;
	}
}

void	check_for_3_in_4_p1(int board[4][4][13], int i, int j)
{
	int tmp[3];

	while (i < 4)
	{
		tmp[0] = 0;
		tmp[1] = 0;
		tmp[2] = 0;
		j = 0;
		while (j < 4)
		{
			if (board[j][i][0] == 0)
			{
				tmp[0] += 1;
				tmp[1] = j;
			}
			tmp[2] += board[j][i][0];
			j++;
		}
		if (tmp[0] == 1)
			board[tmp[1]][i][0] = 10 - tmp[2];
		i++;
	}
}

void	check_for_3_in_4_p2(int board[4][4][13], int i, int j)
{
	int tmp[3];

	while (i < 4)
	{
		tmp[0] = 0;
		tmp[1] = 0;
		tmp[2] = 0;
		j = 0;
		while (j < 4)
		{
			if (board[i][j][0] == 0)
			{
				tmp[0] += 1;
				tmp[1] = j;
			}
			tmp[2] += board[i][j][0];
			j++;
		}
		if (tmp[0] == 1)
			board[i][tmp[1]][0] = 10 - tmp[2];
		i++;
	}
}
