/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:51:47 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 11:13:20 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < length - 1 && is_sorted)
	{
		if (f(tab[i], tab [i + 1]) < 0)
			is_sorted = 0;
		i++;
	}
	if (is_sorted != 1)
	{
		is_sorted = 1;
		i = 0;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
