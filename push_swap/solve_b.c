/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:04:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 18:04:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_b(t_stack *stack)
{
	int			a;
	int			b;
	int			side;

	while (stack->len_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack, &a, &b);
		efficient_rr(stack, &a, &b);
		efficient_ra(stack, a);
		efficient_rb(stack, b);
		push_a(stack);
	}
	print_stack(stack);
	side = get_min_index(stack);
	printf("index %d\n", side);
	if (side > (stack->len_a + 1) / 2)
		side = (stack->len_a - side) * -1;
	efficient_ra(stack, side);
	printf("side %d\n", side);
	print_stack(stack);
}
