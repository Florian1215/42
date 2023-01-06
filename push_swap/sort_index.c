/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:24:04 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/30 23:55:57 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *tab, int i, int j)
{
	int	tmp;

	if (i != j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
	}
}

static int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	i;

	pivot = tab[end];
	i = start;
	while (start < end)
	{
		if (tab[start] <= pivot)
			swap(tab, start, i++);
		start++;
	}
	swap(tab, i, end);
	return (i);
}

static void	quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(tab, start, end);
		quick_sort(tab, start, pivot - 1);
		quick_sort(tab, pivot + 1, end);
	}
}

static int	find_index(int *sort_stack, int nb)
{
	int	i;

	i = 0;
	while (1)
		if (sort_stack[i++] == nb)
			return (i - 1);
}

void	get_index(t_stack *stack)
{
	int	*sorted_stack;
	int	i;

	sorted_stack = malloc(sizeof(int) * stack->len);
	if (!sorted_stack)
		return ;
	i = -1;
	while (i++ < stack->len)
		sorted_stack[i] = stack->a[i];
	quick_sort(sorted_stack, 0, stack->len - 1);
	i = -1;
	while (++i < stack->len)
		stack->a[i] = find_index(sorted_stack, stack->a[i]);
	free(sorted_stack);
}
