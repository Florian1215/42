/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:04:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 18:04:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3chunck(t_stack *stack, int pivot1, int pivot2)
{
	if (stack->a[0] < pivot1)
	{
		push_b(stack);
		rotate_b(stack);
	}
	else if (stack->a[0] < pivot2)
		push_b(stack);
	else
		rotate_a(stack);
}

void	solve(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
		sort_3chunck(stack, stack->len_a / 3, stack->len_a / 3 * 2);
	while (stack->len_a > 3)
		push_b(stack);
	if (stack->len_a == 3)
		solve3(stack);
	if (stack->len_a == 2 && stack->a[0] > stack->a[1])
		swap_a(stack);
	print_stack(stack);
	solve_b(stack);
}
