/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:49:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 17:49:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve5_2(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (stack->a[i] == 0)
			return (rotate_a(stack));
	return (reverse_rotate_a(stack));
}

void	solve5(t_stack *stack)
{
	push_b(stack);
	push_b(stack);
	solve3(stack);
	while (stack->len_b)
	{
		if (is_sort(stack, 0) && stack->b[0] > stack->a[stack->len_a - 1])
		{
			push_a(stack);
			rotate_a(stack);
		}
		else if ((stack->b[0] < stack->a[0] && stack->b[0] > \
			stack->a[stack->len_a - 1]) || (is_sort(stack, 0) \
			&& (stack->b[0] == 0 || (stack->len_b == 2 && stack->b[0] == 1 \
			&& stack->b[1] == 0))))
			push_a(stack);
		else
			rotate_a(stack);
	}
	while (!is_sort(stack, 0))
		solve5_2(stack);
}
