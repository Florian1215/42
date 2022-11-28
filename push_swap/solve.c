/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:39:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 12:56:18 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_nb(int nb, int index)
{
	int	i;

	i = -1;
	while (++i < index && nb)
		nb /= 10;
	return (nb % 10);
}

static int	rec_exit(t_stack *stack, int index)
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

	if (rec_exit(stack, index))
		return ;
	i = -1;
	len = stack->len_a;
	while (++i < len)
	{
		if (!index_nb(stack->a[0], index))
			push_b(stack);
		else
			rotate_a(stack);
	}
	i = -1;
	len = stack->len_b;
	while (++i < len)
		push_a(stack);
	solve(stack, index + 1);
}

void	solve_selection_sort(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	if (!stack->len_a)
	{
		while (++i < stack->len)
			push_a(stack);
		return ;
	}
	while (++i < stack->len_a)
		if (i == 0 || stack->a[i] < stack->a[min])
			min = i;
	i = -1;
	while (++i < min)
		rotate_a(stack);
	push_b(stack);
	return (solve_selection_sort(stack));
}
