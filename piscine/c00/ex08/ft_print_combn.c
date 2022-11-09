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

void	ft_printing(int array[], int lenght)
{
	int		i;
	char	c;

	i = -1;
	while (++i < lenght)
	{
		c = array[i] + '0';
		write(1, &c, 1);
	}
	if (array[0] != 10 - lenght)
		write(1, ", ", 2);
}

void	ft_recursive(int array[], int lenght, int i)
{
	if (i == 0)
		array[i] = 0;
	else
		array[i] = array[i - 1] + 1;
	while (array[i] < 11 - lenght + i)
	{
		if (i == lenght - 1)
			ft_printing(array, lenght);
		else
			ft_recursive(array, lenght, i + 1);
		array[i] = array[i] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	ft_recursive(array, n, 0);
}
