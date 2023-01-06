/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_smart_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:44:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/30 11:44:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_b(t_stack *stack)
{
	int			a;
	int			b;

	while (stack->len_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack, &a, &b);
		efficient_rr(stack, &a, &b);
		efficient_move(stack, A, a);
		efficient_move(stack, B, b);
		pa(stack);
	}
	efficient_move(stack, A, get_side(get_min_index(stack), stack->len_a));
}

void	solve_smart_sort(t_stack *stack)
{
	int	i;
	int	pivot1;
	int	pivot2;

	i = -1;
	pivot1 = stack->len_a / 3;
	pivot2 = stack->len_a / 3 * 2;
	while (++i < stack->len)
	{
		if (stack->a[0] < pivot1)
		{
			pb(stack);
			rb(stack);
		}
		else if (stack->a[0] < pivot2)
			pb(stack);
		else
			ra(stack);
	}
	while (stack->len_a > 3)
		pb(stack);
	solve3(stack);
	solve_b(stack);
}
