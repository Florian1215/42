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

void	solve3(t_stack *stack)
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

static void	solve5_2(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (stack->a[i] == 0)
			return (ra(stack));
	return (ra(stack));
}

static void	solve5(t_stack *stack)
{
	pb(stack);
	pb(stack);
	solve3(stack);
	while (stack->len_b)
	{
		if (is_sort(stack, 0) && stack->b[0] > stack->a[stack->len_a - 1])
		{
			pa(stack);
			ra(stack);
		}
		else if ((stack->b[0] < stack->a[0] && stack->b[0] > \
			stack->a[stack->len_a - 1]) || (is_sort(stack, 0) \
			&& (stack->b[0] == 0 || (stack->len_b == 2 && stack->b[0] == 1 \
			&& stack->b[1] == 0))))
			pa(stack);
		else
			ra(stack);
	}
	while (!is_sort(stack, 0))
		solve5_2(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = parsing(--ac, ++av);
	if (!stack)
		return (1);
	stack->print = 1;
	if (!is_sort(stack, 0))
	{
		if (stack->len == 3)
			solve3(stack);
		else if (stack->len == 5)
			solve5(stack);
		else if (stack->len == 6)
			solve_radix(stack);
		else
			solve_smart_sort(stack);
	}
	free_stack(stack, ALL);
}
