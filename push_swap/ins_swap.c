/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:55:25 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:32:14 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *stack, int len)
{
	int	tmp;

	if (len > 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	swap_a(t_stack *stack, int print)
{
	swap(stack->a, stack->len_a);
	if (print)
		ft_putstr_nl("sa");
}

void	swap_b(t_stack *stack, int print)
{
	swap(stack->b, stack->len_b);
	if (print)
		ft_putstr_nl("sb");
}

void	swap_ab(t_stack *stack, int print)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	if (print)
		ft_putstr_nl("ss");
}
