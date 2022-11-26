/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:55 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/26 12:16:56 by fguirama         ###   ########.fr       */
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

void	reverse_a(t_stack *stack, int print)
{
	reverse(stack->a, &stack->len_a);
	if (print)
		ft_putstr_nl("rra");
}

void	reverse_b(t_stack *stack, int print)
{
	reverse(stack->b, &stack->len_b);
	if (print)
		ft_putstr_nl("rrb");
}

void	reverse_ab(t_stack *stack)
{
	reverse_a(stack, 0);
	reverse_b(stack, 0);
	ft_putstr_nl("rrr");
}
