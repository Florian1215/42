/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:35:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 16:00:55 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

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

void	move_up(int *stack, int *len)
{
	int	i;

	i = -1;
	*len -= 1;
	while (++i < *len)
		stack[i] = stack[i + 1];
}

void	move_down(int *stack, int *len)
{
	int	i;

	i = 0;
	while (++i <= *len)
		stack[*len - i + 1] = stack[*len - i];
	*len += 1;
}
