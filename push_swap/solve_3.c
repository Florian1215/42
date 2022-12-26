/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:49:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 17:49:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve3(t_stack *stack)
{
	if (is_sort(stack, 0))
		return ;
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack->a[2] < stack->a[1] && stack->a[2] < stack->a[0])
	{
		if (stack->a[1] < stack->a[0])
			swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (stack->a[2] > stack->a[0])
		swap_a(stack);
	else
		rotate_a(stack);
}