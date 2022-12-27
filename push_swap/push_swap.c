/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:35:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/27 14:35:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve3(t_stack *stack)
{
	if (is_sort(stack, 0) || stack->len_a != 3)
		return ;
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2])
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->a[2] < stack->a[1] && stack->a[2] < stack->a[0])
	{
		if (stack->a[1] < stack->a[0])
			sa(stack);
		rra(stack);
	}
	else if (stack->a[2] > stack->a[0])
		sa(stack);
	else
		ra(stack);
}

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

static void	solve(t_stack *stack)
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
	if (stack->len_a == 2 && stack->a[0] > stack->a[1])
		sa(stack);
	solve_b(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (0);
	stack = parsing(--ac, ++av);
	if (!stack)
		return (1);
	stack->print = 1;
	if (!is_sort(stack, 0))
	{
		if (stack->len == 3)
			solve3(stack);
		else
			solve(stack);
	}
	free_stack(stack, ALL);
}
