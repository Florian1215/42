/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:55:25 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/23 14:20:48 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, int len)
{
	int	tmp;

	if (len > 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	swap_a(t_stack *stack)
{
	swap(stack->a, stack->len_a);
}

void	swap_b(t_stack *stack)
{
	swap(stack->b, stack->len_b);
}

void	swap_all(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
