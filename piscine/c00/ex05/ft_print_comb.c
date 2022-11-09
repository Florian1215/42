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

void	ft_printing(int array[])
{
	int		i;
	char	c;

	i = -1;
	while (++i < 3)
	{
		c = array[i] + '0';
		write(1, &c, 1);
	}
	if (array[0] != 10 - 3)
		write(1, ", ", 2);
}

void	ft_recursive(int array[], int i)
{
	if (i == 0)
		array[i] = 0;
	else
		array[i] = array[i - 1] + 1;
	while (array[i] < 11 - 3 + i)
	{
		if (i == 3 - 1)
			ft_printing(array);
		else
			ft_recursive(array, i + 1);
		array[i] = array[i] + 1;
	}
}

void	ft_print_comb(void)
{
	int	array[3];

	ft_recursive(array, 0);
}
