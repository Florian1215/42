/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:14:28 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/24 12:38:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Selection sort:
*/

void	solve(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	if (!(*stack).len_a)
	{
		while (++i < (*stack).len)
			push_a(stack);
		return ;
	}
	while (++i < (*stack).len_a)
		if (i == 0 || (*stack).a[i] < (*stack).a[min])
			min = i;
	i = -1;
	while (++i < min)
		rotate_a(stack);
	push_b(stack);
	return (solve(stack));
}
