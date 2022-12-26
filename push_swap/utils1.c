/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:28:17 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/30 22:39:35 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str_nl(char *str)
{
	while (*str)
		put_char(*str++);
	put_char('\n');
}

void	error_(t_stack *stack)
{
	if (stack)
		free_stack(stack, ALL);
	write(2, "Error\n", 6);
	exit(-1);
}

void	*free_stack(t_stack *stack, t_free_stacks stacks)
{
	if (stacks)
		free(stack->a);
	if (stacks == ALL)
		free(stack->b);
	free(stack);
	return (NULL);
}

int	is_sort(t_stack *stack, int check_b)
{
	int	i;

	if (stack->len_b && check_b)
		return (0);
	i = 0;
	while (++i < stack->len_a)
		if (stack->a[i] < stack->a[i - 1])
			return (0);
	return (1);
}
