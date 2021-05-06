/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:27:23 by tjensen           #+#    #+#             */
/*   Updated: 2021/05/02 17:18:23 by dnunes-a         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	ft_verify(argc, argv[1]);
	return (0);
	
}
