/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 08:59:09 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/02 17:09:40 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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


int	**create_matrix(int value, int row, int column)
{
	int **matrix;
	int i;
	int j;

	matrix = (int**)malloc(row * sizeof(int*));
	i = 0;
	while (i < row)
	{
		matrix[i] = (int*)malloc(column * sizeof(int));
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = value;
			j++;
		}	
		i++;
	}
	return matrix;
}

void	ft_malloc_matrix(int ***matrix)
{
	matrix[0] = create_matrix(0, 4, 4);
	matrix[1] = create_matrix(0, 4, 4);
	matrix[2] = create_matrix(0, 4, 4);
	matrix[3] = create_matrix(0, 4, 4);
}


void	ft_logic_start(char *values)
{
	int ***possibilities_up;
	int ***possibilities_do;
	int ***possibilities_le;
	int ***possibilities_ri;
	int **matrix_checker;
	int **matrix_resp;

	possibilities_up = (int***)malloc(4 * sizeof(int**));
	possibilities_do = (int***)malloc(4 * sizeof(int**));
	possibilities_le = (int***)malloc(4 * sizeof(int**));
	possibilities_ri = (int***)malloc(4 * sizeof(int**));
	matrix_resp = (int**)malloc(4 * sizeof(int*));
	matrix_checker = (int**)malloc(4 * sizeof(int*));
	ft_malloc_matrix(possibilities_up);
	ft_malloc_matrix(possibilities_do);
	ft_malloc_matrix(possibilities_le);
	ft_malloc_matrix(possibilities_ri);
	populate_matrix_up(values, possibilities_up);
	populate_matrix_do(values, possibilities_do);
	populate_matrix_le(values, possibilities_le);
	populate_matrix_ri(values, possibilities_ri);
}