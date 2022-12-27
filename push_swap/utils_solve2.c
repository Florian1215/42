/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solve2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:43:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/27 14:43:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int n)
{
	return (n * (-1 * (n < 0) + (n > 0)));
}

void	efficient_move(t_stack *stack, t_stacks s, int index)
{
	static	void	(*func_side[2][2])() = {{rb, rrb}, \
											{ra, rra}};

	while (index)
	{
		func_side[s][index < 0](stack);
		index += 1 - ((index > 0) * 2);
	}
}

void	efficient_rr(t_stack *stack, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stack);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stack);
		*a += 1;
		*b += 1;
	}
}

static int	get_mid_index(t_stack *stack, int nb)
{
	int	i;

	i = -1;
	while (++i + 1 < stack->len_a)
		if (nb > stack->a[i] && nb < stack->a[i + 1])
			break ;
	return (get_side(++i, stack->len_a));
}

void	get_min_rotate(t_stack *stack, int *a, int *b)
{
	int	index_a;
	int	index_b;
	int	i;

	i = -1;
	while (++i < stack->len_b)
	{
		if (stack->b[i] < get_min(stack))
			index_a = get_min_index(stack);
		else if (stack->b[i] > get_max(stack))
			index_a = get_max_index(stack);
		else
			index_a = get_mid_index(stack, stack->b[i]);
		index_b = get_side(i, stack->len_b);
		if (!i || abs(index_a) + abs(index_b) < abs(*a) + abs(*b))
		{
			*a = index_a;
			*b = index_b;
		}
	}
}
