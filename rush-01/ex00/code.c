#include <stdio.h>
// "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// "1 2 3 3 3 3 1 2 1 2 2 2 4 3 1 2"
// "2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 3"
// "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1"
// "3 3 2 1 1 2 3 3 3 3 2 1 1 2 3 3"
// "2 2 2 1 3 2 1 4 4 1 2 3 1 2 2 2"
// "2 3 1 2 2 2 3 1 3 1 2 2 2 3 3 1"
// "1 2 2 2 4 1 2 3 1 2 2 2 4 1 2 3"
// "4 1 2 2 1 4 2 2 2 3 2 1 3 2 1 2"
// "2 2 1 2 3 1 4 2 3 1 2 2 2 3 1 2"
// "1 3 2 3 3 1 3 2 1 2 3 2 3 2 1 2"
// "1 2 2 3 3 1 2 2 1 2 2 2 4 2 1 3"

// "3 3 2 1 1 2 2 3 3 3 2 1 1 2 2 4"
// "2 2 1 4 2 3 3 1 2 3 1 2 2 3 2 1"
// "3 3 2 1 1 2 2 4 3 3 2 1 1 2 2 3"

// "1 2 2 3 3 1 2 2 1 2 2 2 4 2 1 3"

// "2 3 1 2 2 3 2 1 2 2 1 4 2 3 3 1"
// 2 1 4 3
// 2 4 3 1
// 4 3 1 2
// 1 2 3 4

int		assign_input(int ip_col[4][2], int ip_row[2][4], char *argv[]);
void	zero_board(int board[4][4][13]);
void	print_board(int board[4][4][13], int layer);
void	write_in_board(int board[4][4][13], char nbrs[5], int j, char cords[3]);
void	store_all_poss_combs(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	assign_definite_values(int board[4][4][13], int ip_col[4][2], int ip_row[2][4]);
void	check_for_3_in_4(int board[4][4][13]);
void	stamp_duplicates(int  board[4][4][13], int z_min, int z_max);
void	erase_conflicting_rows(int board[4][4][13]);
void	erase_conflicting_cols(int board[4][4][13]);
void	check_for_1_sol_left_rows(int board[4][4][13]);
void	check_for_1_sol_left_cols(int board[4][4][13]);
void	perform_algorithm(int board[4][4][13]);
int		check_for_valid_board(int board[4][4][13]);
void	branch_col_variation(int board[4][4][13], int board_bu[4][4][13]);
void	copy_cube(int board[4][4][13], int board_bu[4][4][13]);
void	solve_4_empty_slots_problem(int board[4][4][13]);

int		main(int argc, char *argv[])
{
	int ip_col[4][2];
	int ip_row[2][4];
	int board[4][4][13];
	int board_bu[4][4][13];
	zero_board(board);
	if (assign_input(ip_col, ip_row, argv) == -1 || argc != 2)
	{
		printf("Error\n");
		return 0;
	}
	assign_definite_values(board, ip_col, ip_row);
	store_all_poss_combs(board, ip_col, ip_row);
	perform_algorithm(board);

	int i = 0;
	// i = 0;
	// while (i < 13)
	// {
	// 	print_board(board, i);
	// 	printf("\n");
	// 	i++;
	// }
	i = 0;
	while (i < 8)
	{
		// printf("MAIN LOOP with i = %d\n", i);
		if (check_for_valid_board(board) == -1)
		{
			copy_cube(board, board_bu);
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

	// printf("\n");
	// i = 0;
	// while (i < 13)
	// {
	// 	print_board(board, i);
	// 	printf("\n");
	// 	i++;
	// }

	if (check_for_valid_board(board) == 40)
			print_board(board, 0);
	else
		printf("Error\n");
}

void	solve_4_empty_slots_problem(int board[4][4][13])
{
	int x = 0;
	int y = 0;
	int i = 0;
	int zero_counter = 0;
	int present_nbrs[5] = {0,0,0,0,0};
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (board[x][y][0] == 0)
			{
				zero_counter++;
			}
			y++;
		}
		x++;
	}
	if (zero_counter != 4)
		return;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (board[x][y][0] == 0)
			{
				i = 0;
				while (i < 4)
				{
					present_nbrs[board[i][y][0]] = board[i][y][0];
					present_nbrs[board[x][i][0]] = board[x][i][0];
					i++;
				}
				i = 1;
				while (i < 5)
				{
					if (present_nbrs[i] == 0)
					{
						board[x][y][0] = i;
						return ;
					}
					i++;
				}
			}
			y++;
		}
		x++;
	}
}

void	perform_algorithm(int board[4][4][13])
{
	int i = 0;
	while (i < 8)
	{
		// printf("Initialized with i = %d ", i);
		// printf("before:\n");
		// print_board(board, 0);

		stamp_duplicates(board, 1, 6);
		stamp_duplicates(board, 7, 12);
		erase_conflicting_cols(board);
		erase_conflicting_rows(board);
		check_for_1_sol_left_cols(board);
		// 				printf("after:\n");
		// print_board(board, 0);
		// printf("\n");
		check_for_1_sol_left_rows(board);
		check_for_3_in_4(board);


		i++;
	}
}

int		check_for_valid_board(int board[4][4][13])
{
	int x = 0;
	int y = 0;
	int x2;
	int y2;
	int total_sum = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			total_sum += board[x][y][0];
			x2 = x;
			while (x2 < 4)
			{
				if (board[x][y][0] == board[x2][y][0] && x != x2)
					return -1;
				x2++;
			}
			y2 = y;
			while (y2 < 4)
			{
				if (board[x][y][0] == board[x][y2][0] && y != y2)
					return -1;
				y2++;
			}
			y++;
		}
		x++;
	}
	return total_sum;
}

void	branch_col_variation(int board[4][4][13], int board_bu[4][4][13])
{
	int x = 0;
	int z = 1;
	int val_y = 0;
	int val_z = 7;
	int zero_counter = 0;
	int digit_valid = 0;
	while (x < 4) // x=3 y=0 z=2
	{
		z = 1;
		while (z < 7)
		{
			if (board[x][0][z] != 0)
			{
				digit_valid = 0;
				val_y = 0;
				while (val_y < 4)
				{
					zero_counter = 0;
					val_z = 7;
					while (val_z < 13)
					{
						// printf("board[%d][%d][%d] = %d && board[%d][%d][%d] = %d\n", x, val_y, val_z, board[x][val_y][val_z], x, val_y, z, board[x][val_y][z]);
						if (board[x][val_y][val_z] != 0 && board[x][val_y][val_z] == board[x][val_y][z])
						{
							digit_valid++;
							break ;
						}
						else if (board[x][val_y][val_z] == 0)
							zero_counter++;
						val_z++;
					}
					if (zero_counter == 6)
						digit_valid++;
					val_y++;
				}
				// printf("digit_valid = %d\n", digit_valid);
				if (digit_valid == 4)
				{
					//print_board(board, 0);
					// printf("ERASING____\n");
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
					//print_board(board, 0);
					return ;
				}
				else
				{
					// printf("ERASING\n");
					board[x][0][z] = 0;
					board[x][1][z] = 0;
					board[x][2][z] = 0;
					board[x][3][z] = 0;
					board_bu[x][0][z] = 0;
					board_bu[x][1][z] = 0;
					board_bu[x][2][z] = 0;
					board_bu[x][3][z] = 0;
				}
			}
			z++;
		}
		x++;
	}
}

void	copy_cube(int board[4][4][13], int board_bu[4][4][13])
{
	int x = 0;
	int y = 0;
	int z = 0;
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

void	check_for_1_sol_left_rows(int board[4][4][13])
{
	int x = 0;
	int y = 0; 
	int z = 7;
	int z_sol = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
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
			{
				board[0][y][0] = board[0][y][z_sol];
				board[1][y][0] = board[1][y][z_sol];
				board[2][y][0] = board[2][y][z_sol];
				board[3][y][0] = board[3][y][z_sol];
			}
			z_sol = 0;
			y++;
		}
		x++;
	}
}

void	check_for_1_sol_left_cols(int board[4][4][13])
{
	int x = 0;
	int y = 0; 
	int z = 1;
	int z_sol = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
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
			{
				board[x][0][0] = board[x][0][z_sol];
				board[x][1][0] = board[x][1][z_sol];
				board[x][2][0] = board[x][2][z_sol];
				board[x][3][0] = board[x][3][z_sol];
			}
			z_sol = 0;
			y++;
		}
		x++;
	}
}

void	erase_conflicting_rows(int board[4][4][13])
{
	int x = 0;
	int y = 0; 
	int z = 7;
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

void	erase_conflicting_cols(int board[4][4][13])
{
	int x = 0;
	int y = 0; 
	int z = 1;
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

void	stamp_duplicates(int board[4][4][13], int z_min, int z_max)
{
	int x = 0;
	int y = 0; 
	int z = z_min;
	int tmp = 0;
	int duplicate_found = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z = z_min;
			while (z <= z_max)
			{
				if (board[x][y][z] != 0 && tmp == 0)
					tmp = board[x][y][z];
				else if (board[x][y][z] != 0 && tmp != board[x][y][z])
					duplicate_found = -1;
				z++;
			}
			if (duplicate_found == 0 && tmp != 0 && board[x][y][0] == 0)
				board[x][y][0] = tmp;
			duplicate_found = 0;
			tmp = 0;
			y++;
		}
		x++;
	}
}

void	write_in_board(int board[4][4][13], char nbrs[5], int i, char cords[3])
{
	int j = 0;
	while (j < 4)
	{
		if (cords[0] == 'X')
			board[i][j][cords[1] - 48] = nbrs[j] - 48;
		if (cords[0] == 'Y')
			board[j][i][cords[1] - 48] = nbrs[j] - 48;
		j++;
	}
}

void	store_all_poss_combs(int board[4][4][13], int ip_col[4][2], int ip_row[2][4])
{
	int i = 0;
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
		{
			write_in_board(board, "3214", i, "X1");
			write_in_board(board, "3124", i, "X2");
		}
		else if (ip_col[i][0] == 3 && ip_col[i][1] == 2)
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
	i = 0;
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
		{
			write_in_board(board, "3214", i, "Y7");
			write_in_board(board, "3124", i, "Y8");
		}
		else if (ip_row[0][i] == 3 && ip_row[1][i] == 2)
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

void	assign_definite_values(int board[4][4][13], int ip_col[4][2], int ip_row[2][4])
{
	int i = 0;
	while (i < 4) // the 4 clue
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
	while (i < 4) // the 1 clue
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
	i = 0;
	while (i < 4) // the 3 clue
	{
		if (ip_col[i][0] == 3 && board[i][3][0] == 3 && board[i][2][0] == board[i][1][0] && board[i][0][0] == 0)
		{
			board[i][2][0] = 4;
			board[i][1][0] = 2;
			board[i][0][0] = 1;
		}
		if (ip_col[i][1] == 3 && board[i][0][0] == 3 && board[i][1][0] == board[i][2][0] && board[i][3][0] == 0)
		{
			board[i][1][0] = 4;
			board[i][2][0] = 2;
			board[i][3][0] = 1;
		}
		if (ip_row[0][i] == 3 && board[3][i][0] == 3 && board[2][i][0] == board[1][i][0] && board[0][i][0] == 0)
		{
			board[2][i][0] = 4;
			board[1][i][0] = 2;
			board[0][i][0] = 1;
		}
		if (ip_row[1][i] == 3 && board[0][i][0] == 3 && board[1][i][0] == board[2][i][0] && board[3][i][0] == 0)
		{
			board[1][i][0] = 4;
			board[2][i][0] = 2;
			board[3][i][0] = 1;
		}
		i++;
	}
	i = 0;
	while (i < 4) // the 2 clue
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

void	check_for_3_in_4(int board[4][4][13])
{
	int i = 0;
	int j = 0;
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
	i = 0;
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

int		assign_input(int ip_col[4][2], int ip_row[2][4], char *argv[])
{
	int i = 0;
	while (i < 16)
	{
		if (argv[1][i * 2] < '1' || argv[1][i * 2] > '4')
			return -1;
		if (i != 0 && argv[1][i * 2 - 1] != ' ')
			return -1;
		if (i == 15 && argv[1][i * 2 + 1] != '\0')
			return -1;
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
	return 0;
}

void	zero_board(int board[4][4][13])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 13; k++)
			{
				board[i][j][k] = 0;
			}
		}
	}
}

void	print_board(int board[4][4][13], int layer)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d", board[j][i][layer]);
			if (j != 3)
				printf(" ");
		}
		printf(" ");
	}
	printf("\n");
}
