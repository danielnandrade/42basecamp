/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:07:00 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/02 17:09:49 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	populate_matrix_up(char *values, int ***matrix)
{
	int i;
	int l;
	int c;

	c = 0;
	i = 0;
	while (i < 8)
	{
		if(values[i] == '1')
		{
			matrix[3][0][c] = '4' - '0';
			l = 1;
			while(l < 4)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				l++;
			}
			c++;
		}
		else if (values[i] == '2')
		{
			matrix[0][0][c] = '1' - '0';
			matrix[1][0][c] = '2' - '0';
			matrix[2][0][c] = '3' - '0';
			l = 1;
			while(l < 4)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				matrix[3][l][c] = '4' - '0';
				l++;
			}
			c++;
		}
		else if (values[i] == '3')
		{
			matrix[0][0][c] = '1' - '0';
			matrix[1][0][c] = '2' - '0';
			l = 1;
			while (l < 4)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				if (l != 1)
					matrix[3][l][c] = '4' - '0';
				l++;
			}
			c++;
		}
		else if (values[i] == '4')
		{
			matrix[0][0][c] = '1' - '0';
			matrix[1][1][c] = '2' - '0';
			matrix[2][2][c] = '3' - '0';
			matrix[3][3][c] = '4' - '0';
			c++;
		}	
		i++;
	}
}

void	populate_matrix_do(char *values, int ***matrix)
{
	int i;
	int l;
	int c;

	c = 0;
	i = 8;
	while (i < 16)
	{
		if(values[i] == '1')
		{
			matrix[3][3][c] = '4' - '0';
			l = 2;
			while(l >= 0)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				l--;
			}
			c++;
		}
		else if (values[i] == '2')
		{
			matrix[0][3][c] = '1' - '0';
			matrix[1][3][c] = '2' - '0';
			matrix[2][3][c] = '3' - '0';
			l = 2;
			while(l >= 0)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				matrix[3][l][c] = '4' - '0';
				l--;
			}
			c++;
		}
		else if (values[i] == '3')
		{
			matrix[0][3][c] = '1' - '0';
			matrix[1][3][c] = '2' - '0';
			l = 2;
			while (l >= 0)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				if (l != 1)
					matrix[3][l][c] = '4' - '0';
				l--;
			}
			c++;
		}
		else if (values[i] == '4')
		{
			matrix[0][3][c] = '1' - '0';
			matrix[1][2][c] = '2' - '0';
			matrix[2][1][c] = '3' - '0';
			matrix[3][0][c] = '4' - '0';
			c++;
		}	
		i++;
	}
}

void	populate_matrix_le(char *values, int ***matrix)
{
	int i;
	int l;
	int c;

	l = 0;
	i = 16;
	while (i < 24)
	{
		if(values[i] == '1')
		{
			matrix[3][l][0] = '4' - '0';
			c = 1;
			while(c < 4)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				c++;
			}
			l++;
		}
		else if (values[i] == '2')
		{
			matrix[0][l][0] = '1' - '0';
			matrix[1][l][0] = '2' - '0';
			matrix[2][l][0] = '3' - '0';
			c = 1;
			while(c < 4)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				matrix[3][l][c] = '4' - '0';
				c++;
			}
			l++;
		}
		else if (values[i] == '3')
		{
			matrix[0][l][0] = '1' - '0';
			matrix[1][l][0] = '2' - '0';
			c = 1;
			while (c < 4)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				if (l != 1)
					matrix[3][l][c] = '4' - '0';
				c++;
			}
			l++;
		}
		else if (values[i] == '4')
		{
			matrix[0][l][0] = '1' - '0';
			matrix[1][l][1] = '2' - '0';
			matrix[2][l][2] = '3' - '0';
			matrix[3][l][3] = '4' - '0';
			l++;
		}	
		i++;
	}
}

void	populate_matrix_ri(char *values, int ***matrix)
{
	int i;
	int l;
	int c;

	l = 0;
	i = 24;
	while (i < 32)
	{
		if(values[i] == '1')
		{
			matrix[3][l][3] = '4' - '0';
			c = 2;
			while(c >= 0)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				c--;
			}
			l++;
		}
		else if (values[i] == '2')
		{
			matrix[0][l][3] = '1' - '0';
			matrix[1][l][3] = '2' - '0';
			matrix[2][l][3] = '3' - '0';
			c = 2;
			while(c >= 0)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				matrix[3][l][c] = '4' - '0';
				c--;
			}
			l++;
		}
		else if (values[i] == '3')
		{
			matrix[0][l][3] = '1' - '0';
			matrix[1][l][3] = '2' - '0';
			c = 2;
			while (c >= 0)
			{
				matrix[0][l][c] = '1' - '0';
				matrix[1][l][c] = '2' - '0';
				matrix[2][l][c] = '3' - '0';
				if (l != 1)
					matrix[3][l][c] = '4' - '0';
				c--;
			}
			l++;
		}
		else if (values[i] == '4')
		{
			matrix[0][l][3] = '1' - '0';
			matrix[1][l][2] = '2' - '0';
			matrix[2][l][1] = '3' - '0';
			matrix[3][l][0] = '4' - '0';
			l++;
		}	
		i++;
	}
}