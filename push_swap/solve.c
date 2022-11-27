/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:39:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/27 09:32:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_nb(int nb, int index)
{
	int	i;

	i = -1;
	while (++i < index && nb)
		nb /= 10;
	return (nb % 10);
}

int	exit_loop(t_stack *stack, int index)
{
	int	i;

	i = -1;
	while (++i < stack->len_a)
		if (index_nb(stack->a[i], index))
			return (0);
	return (1);
}

void	solve(t_stack *stack, int index)
{
	int	i;
	int	len;

	if (exit_loop(stack, index))
		return ;
	i = -1;
	len = stack->len_a;
	while (++i < len)
	{
		if (!index_nb(stack->a[0], index))
			push_b(stack);
		else
			rotate_a(stack, 1);
	}
	i = -1;
	len = stack->len_b;
	while (++i < len)
		push_a(stack);
	solve(stack, index + 1);
}
