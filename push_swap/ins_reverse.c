/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:55 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:30:55 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(int *stack, int *len)
{
	int	tmp;

	if (*len <= 1)
		return ;
	*len -= 1;
	tmp = stack[*len];
	move_down(stack, len);
	stack[0] = tmp;
}

void	reverse_rotate_a(t_stack *stack)
{
	reverse(stack->a, &stack->len_a);
	if (stack->print)
		put_str_nl("rra");
}

void	reverse_rotate_b(t_stack *stack)
{
	reverse(stack->b, &stack->len_b);
	if (stack->print)
		put_str_nl("rrb");
}

void	reverse_rotate_ab(t_stack *stack)
{
	reverse(stack->a, &stack->len_a);
	reverse(stack->b, &stack->len_b);
	if (stack->print)
		put_str_nl("rrr");
}
