/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:19:52 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/10 10:50:47 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_print_pos(char *tab, int *n_tot)
{
	int	i;

	i = 0;
	while (i < 10)
		ft_putchar(tab[i++] + '0');
	ft_putchar('\n');
	(*n_tot)++;
}

void	ft_recursive(char *tab, int n_queen, int *n_tot)
{
	int	col;
	int	row;

	if (n_queen == 10)
	{
		ft_print_pos(tab, n_tot);
		return ;
	}
	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < n_queen && col != tab[row] && \
				ft_abs(tab[row] - col) != n_queen - row)
			row++;
		if (row >= n_queen)
		{
			tab[n_queen] = col;
			ft_recursive(tab, n_queen + 1, n_tot);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		n_tot;
	char	tab[10];

	n_tot = 0;
	ft_recursive(tab, 0, &n_tot);
	return (n_tot);
}
