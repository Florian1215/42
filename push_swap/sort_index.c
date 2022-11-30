/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:24:04 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:24:06 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert(int *tab, int tmp, int i)
{
	while (1)
	{
		i--;
		tab[i + 1] = tab[i];
		if (i == 0 || tmp >= tab[i - 1])
		{
			tab[i] = tmp;
			return ;
		}
	}
}

static int	*sort_stack(int *stack, int len)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = stack[i];
	i = -1;
	while (i++ < len - 1)
		if (i != 0 && res[i] < res[i - 1])
			insert(res, res[i], i);
	return (res);
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

	sorted_stack = sort_stack(stack->a, stack->len_a);
	i = -1;
	while (++i < stack->len_a)
		stack->a[i] = find_index(sorted_stack, stack->a[i]);
	free(sorted_stack);
}
