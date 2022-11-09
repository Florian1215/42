/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:23:36 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/06 15:25:47 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_mv_left(int *tab, int temp_tab, int i)
{
	int	bool;

	bool = 1;
	while (bool)
	{
		i--;
		tab[i + 1] = tab[i];
		if (i == 0 || temp_tab >= tab[i - 1])
		{
			tab[i] = temp_tab;
			bool = 0;
		}
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp_tab;
	int	i;

	i = -1;
	while (i++ < size - 1)
	{
		temp_tab = tab[i];
		if (i == 0 || temp_tab >= tab[i - 1])
			tab[i] = temp_tab;
		else
		{
			ft_mv_left(tab, temp_tab, i);
		}
	}
}
