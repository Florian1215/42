/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:49 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:31:13 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(int *from, int *len_from, int *to, int *len_to)
{
	if (*len_from == 0)
		return ;
	move_down(to, len_to);
	to[0] = from[0];
	move_up(from, len_from);
}

void	pa(t_stack *stack)
{
	push(stack->b, &stack->len_b, stack->a, &stack->len_a);
	if (stack->print)
		put_str_nl("pa");
}

void	pb(t_stack *stack)
{
	push(stack->a, &stack->len_a, stack->b, &stack->len_b);
	if (stack->print)
		put_str_nl("pb");
}
