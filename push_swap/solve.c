/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:39:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 17:45:56 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *stack, int index)
{
	int	i;
	int	len;

	if (is_sort(stack, 1))
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

void	solve3(t_stack *stack)
{
	if (is_sort(stack, 0))
		return ;
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2])
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	else if (stack->a[2] < stack->a[1] && stack->a[2] < stack->a[0])
	{
		if (stack->a[1] < stack->a[0])
			swap_a(stack, 1);
		reverse_a(stack, 1);
	}
	else if (stack->a[2] > stack->a[0])
		swap_a(stack, 1);
	else
		rotate_a(stack, 1);
}

void	solve5_2(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (stack->a[i] == 0)
			return (rotate_a(stack, 1));
	return (reverse_a(stack, 1));
}

void	solve5(t_stack *stack)
{
	push_b(stack, 1);
	push_b(stack, 1);
	solve3(stack);
	while (stack->len_b)
	{
		if (is_sort(stack, 0) && stack->b[0] > stack->a[stack->len_a - 1])
		{
			push_a(stack, 1);
			rotate_a(stack, 1);
		}
		else if ((stack->b[0] < stack->a[0] && stack->b[0] > \
			stack->a[stack->len_a - 1]) || (is_sort(stack, 0) \
			&& (stack->b[0] == 0 || (stack->len_b == 2 && stack->b[0] == 1 \
			&& stack->b[1] == 0))))
			push_a(stack, 1);
		else
			rotate_a(stack, 1);
	}
	while (!is_sort(stack, 0))
		solve5_2(stack);
}
