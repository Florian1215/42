/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:35:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/27 11:38:15 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_power(int nb, int power)
{
	if (power < 1)
		return (!power);
	return (nb * ft_power(nb, power - 1));
}

int	to_binary(int nb)
{
	int	res;
	int	len;
	int	i;

	res = 0;
	len = 0;
	while (ft_power(2, len) <= nb)
		len++;
	i = -1;
	while (++i < len)
	{
		res = (nb % 2) * ft_power(10, i) + res;
		nb /= 2;
	}
	return (res);
}
