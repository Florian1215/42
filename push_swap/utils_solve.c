/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:18:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 18:18:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	i = -1;
	min = -1;
	while (++i < stack->len_a)
		if (min == -1 || stack->a[i] < min)
			min = stack->a[i];
	return (min);
}

int	get_min_index(t_stack *stack)
{
	int	min;
	int	i;

	i = -1;
	min = get_min(stack);
	while (++i < stack->len_a)
		if (stack->a[i] == min)
			return (i);
	return (0);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	i = -1;
	max = -1;
	while (++i < stack->len_a)
		if (max == -1 || stack->a[i] > max)
			max = stack->a[i];
	return (max);
}

int	get_max_index(t_stack *stack)
{
	int	max;
	int	i;

	i = -1;
	max = get_max(stack);
	while (++i < stack->len_a)
		if (stack->a[i] == max)
			return (i);
	return (0);
}
