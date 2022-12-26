/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_rotate_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:09:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 18:09:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	efficient_ra(t_stack *stack, int a)
{
	static void	(*func_side[2])() = {rotate_a, reverse_rotate_a};

	while (a)
	{
		func_side[a < 0](stack);
		a += 1 - ((a > 0) * 2);
	}
}

void	efficient_rb(t_stack *stack, int b)
{
	static void	(*func_side[2])() = {rotate_b, reverse_rotate_b};

	while (b)
	{
		func_side[b < 0](stack);
		b += 1 - ((b > 0) * 2);
	}
}

void	efficient_rr(t_stack *stack, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rotate_ab(stack);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		reverse_rotate_ab(stack);
		*a += 1;
		*b += 1;
	}
}
