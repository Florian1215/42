/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:29:12 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/05 11:18:02 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printing(int tab[], int len)
{
	int		i;
	char	c;

	i = -1;
	while (++i < len)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
	}
	if (tab[0] != 10 - len)
		write(1, ", ", 2);
}

void	ft_recursive(int tab[], int len, int i)
{
	if (i == 0)
		tab[i] = 0;
	else
		tab[i] = tab[i - 1] + 1;
	while (tab[i] < 11 - len + i)
	{
		if (i == len - 1)
			ft_printing(tab, len);
		else
			ft_recursive(tab, len, i + 1);
		tab[i] = tab[i] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];

	ft_recursive(tab, n, 0);
}
