/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:26:01 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/05 11:12:45 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printing(int tab[])
{
	int		i;
	char	c;

	i = -1;
	while (++i < 3)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
	}
	if (tab[0] != 10 - 3)
		write(1, ", ", 2);
}

void	ft_recursive(int tab[], int i)
{
	if (i == 0)
		tab[i] = 0;
	else
		tab[i] = tab[i - 1] + 1;
	while (tab[i] < 11 - 3 + i)
	{
		if (i == 3 - 1)
			ft_printing(tab);
		else
			ft_recursive(tab, i + 1);
		tab[i] = tab[i] + 1;
	}
}

void	ft_print_comb(void)
{
	int	tab[3];

	ft_recursive(tab, 0);
}
