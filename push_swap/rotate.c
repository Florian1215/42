/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:27 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/27 09:33:19 by fguirama         ###   ########.fr       */
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

void	rotate_a(t_stack *stack, int print)
{
	rotate(stack->a, &stack->len_a);
	if (print)
		ft_putstr_nl("ra");
}

void	rotate_b(t_stack *stack, int print)
{
	rotate(stack->b, &stack->len_b);
	if (print)
		ft_putstr_nl("rb");
}

void	rotate_ab(t_stack *stack)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	ft_putstr_nl("rr");
}
