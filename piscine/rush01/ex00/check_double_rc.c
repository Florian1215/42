/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_rc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:56:30 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/14 21:35:01 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#define N_SIZE 4

int	ft_check_double_rc(int tab[N_SIZE][N_SIZE], int pos, int nb);

int	ft_check_double_rc(int tab[N_SIZE][N_SIZE], int pos, int nb)
{
	int	i;

	i = 0;
	while (i < pos / N_SIZE)
	{
		if (tab[i][pos % N_SIZE] == nb)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % N_SIZE)
	{
		if (tab[pos / N_SIZE][i] == nb)
			return (0);
		i++;
	}
	return (1);
}
