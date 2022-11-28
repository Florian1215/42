/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:28:17 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 17:15:41 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_nl(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	error_(t_stack *stack)
{
	free_stack(stack, 1, 1);
	ft_putstr_nl("Error");
	exit(-1);
}

void	*free_stack(t_stack *stack, int free_a, int free_b)
{
	if (free_a)
		free(stack->a);
	if (free_b)
		free(stack->b);
	free(stack);
	return (NULL);
}

int	is_sort(t_stack *stack)
{
	int	i;

	if (stack->len_b)
		return (0);
	i = 0;
	while (++i < stack->len_a)
		if (stack->a[i] < stack->a[i - 1])
			return (0);
	return (1);
}
