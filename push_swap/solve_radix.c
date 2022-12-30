/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:43:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/30 11:43:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_radix(t_stack *stack)
{
	int	index;
	int	i;

	index = 0;
	while (!is_sort(stack, 1))
	{
		i = -1;
		while (++i < stack->len)
		{
			if (stack->a[0] >> index & 1)
				ra(stack);
			else
				pb(stack);
		}
		while (stack->len_b)
			pa(stack);
		index++;
	}
}
