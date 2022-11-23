/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:49 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/23 15:25:15 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *from, int *len_from, int *to, int *len_to)
{
	int	i;

	if (*len_from == 0)
		return ;
	i = 0;
	while (++i < *len_to)
		to[i] = to[i - 1];
	*len_to += 1;
	to[0] = from[0];
	i = 1;
	while (i <= *len_from)
	{
		printf("len = %d - i = %d - replace : %d to %d\n", *len_from, i, to[*len_from - i], to[*len_from - i + 1]);
		to[*len_from - i] = to[*len_from - i + 1];
		i++;
	}
	*len_from -= 1;
}

void	push_a(t_stack *stack)
{
	push(stack->b, &stack->len_b, stack->a, &stack->len_a);
}

void	push_b(t_stack *stack)
{
	push(stack->a, &stack->len_a, stack->b, &stack->len_b);
}
