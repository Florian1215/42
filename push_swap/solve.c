/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:39:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:44:32 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rec_exit(t_stack *stack, int index)
{
	int	i;

	i = -1;
	while (++i < stack->len_a)
		if (stack->a[i] >> index & 1)
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
		if (stack->a[0] >> index & 1)
			rotate_a(stack, 1);
		else
			push_b(stack, 1);
	}
	i = -1;
	len = stack->len_b;
	while (++i < len)
		push_a(stack, 1);
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
			push_a(stack, 1);
		return ;
	}
	while (++i < stack->len_a)
		if (i == 0 || stack->a[i] < stack->a[min])
			min = i;
	i = -1;
	while (++i < min)
		rotate_a(stack, 1);
	push_b(stack, 1);
	return (solve_selection_sort(stack));
}
