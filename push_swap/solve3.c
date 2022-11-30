/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:57:51 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 19:09:14 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve3(t_stack *stack)
{
	if (stack->a[0] == 0)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	else if (stack->a[2] == 0)
	{
		if (stack->a[1] == 1)
			swap_a(stack, 1);
		reverse_a(stack, 1);
	}
	else if (stack->a[0] == 1)
		swap_a(stack, 1);
	else
		rotate_a(stack, 1);
}
