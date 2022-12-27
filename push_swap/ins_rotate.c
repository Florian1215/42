/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:27 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:31:42 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(int *stack, int *len)
{
	int	tmp;

	if (*len <= 1)
		return ;
	tmp = stack[0];
	move_up(stack, len);
	stack[*len] = tmp;
	*len += 1;
}

void	ra(t_stack *stack)
{
	rotate(stack->a, &stack->len_a);
	if (stack->print)
		put_str_nl("ra");
}

void	rb(t_stack *stack)
{
	rotate(stack->b, &stack->len_b);
	if (stack->print)
		put_str_nl("rb");
}

void	rr(t_stack *stack)
{
	rotate(stack->a, &stack->len_a);
	rotate(stack->b, &stack->len_b);
	if (stack->print)
		put_str_nl("rr");
}
