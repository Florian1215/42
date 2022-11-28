/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:55 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 12:57:14 by fguirama         ###   ########.fr       */
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

void	reverse_a(t_stack *stack)
{
	reverse(stack->a, &stack->len_a);
	ft_putstr_nl("rra");
}

void	reverse_b(t_stack *stack)
{
	reverse(stack->b, &stack->len_b);
	ft_putstr_nl("rrb");
}

void	reverse_ab(t_stack *stack)
{
	reverse_a(stack);
	reverse_b(stack);
}
