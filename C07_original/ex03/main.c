/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnunes-a <dnunes-a@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:16:53 by dnunes-a          #+#    #+#             */
/*   Updated: 2021/05/06 21:16:55 by dnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(int size, char **strs, char *sep);
int main()
{
	char *tablo[6];
	tablo[0] = "coucou";
	tablo[1] = "bite";
	tablo[2] = "fesse";
	tablo[3] = "de";
	tablo[4] = "la";
	tablo[5] = "merde";
	printf("%s\n", ft_strjoin(6, tablo, "!"));
	return (0);
}