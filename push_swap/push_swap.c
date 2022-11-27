/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:20 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/26 17:45:19 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	printf("\nA (%d) - B (%d)\n", stack.len_a, stack.len_b);
	while (i < stack.len_a || i < stack.len_b)
	{
		if (i < stack.len_a)
			printf("%d\t", stack.a[i]);
		else
			printf(".\t");
		if (i < stack.len_b)
			printf("%d", stack.b[i]);
		else
			printf(".");
		printf("\n");
		i++;
	}
	printf("\n");
}

/*
Selection sort:


static void	solve2(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	if (!stack->len_a)
	{
		while (++i < stack->len)
			push_a(stack);
		return ;
	}
	while (++i < stack->len_a)
		if (i == 0 || stack->a[i] < stack->a[min])
			min = i;
	i = -1;
	while (++i < min)
		rotate_a(stack, 1);
	push_b(stack);
	return (solve2(stack));
}
*/

int	main(int ac, char **av)
{
	t_stack	stack;

	stack = parsing(--ac, ++av);
	//if (!is_sort(stack))
	solve(&stack, 0);
	print_stack(stack);
	is_sort(stack);
	free_stack(stack);
}
