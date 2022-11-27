/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:28:17 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/26 17:43:08 by fguirama         ###   ########.fr       */
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

void	error_(t_stack stack)
{
	free_stack(stack);
	ft_putstr_nl("Error");
	exit(-1);
}

void	free_stack(t_stack stack)
{
	free(stack.a);
	free(stack.b);
}

int	is_sort(t_stack stack)
{
	int	i;

	if (stack.len_b)
		return (0);
	i = 0;
	while (++i < stack.len_a)
		if (stack.a[i] < stack.a[i - 1])
		{
			printf("%d - %d - %d - %d\n", i, stack.a[i - 1], stack.a[i], stack.a[i + 1]);
			//return (i);
		}
	return (-1);
}
